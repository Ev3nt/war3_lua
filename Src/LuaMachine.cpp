#include "LuaMachine.h"
#include "LuaFunctions.h"
#include "LuaHooks.h"
#include "JassMachine.h"
#include "JassNatives.h"
#include "GameUI.h"
#include "MemHack.h"
#include "Utils.h"
#include "Global.h"
#include <Storm.h>

lua_State* mainState;

void lua_throwerr(lua_State* l);

int stacktrace(lua_State* L);

//----------------------------------------------------------

lua_State* getMainState() {
	if (!mainState) {
		lua_State* l = mainState = luaL_newstate();

		luaL_openlibs(l);
		if (!developerMode) {
			lua_disableFunctions(l);
			lua_replaceFileStreamFunctions(l);
		}
		lua_replaceGlobals(l);
		lua_openJassNatives(l);
		lua_openMemHackAPI(l);
		lua_openFrameAPI(l);
		// lua_open_warcraftfunctions(l);
		lua_replaceSearchers(l);
	}

	return mainState;
}

void destroyMainState()
{
	if (mainState) {
		lua_close(mainState);
		mainState = NULL;

		JassNatives_reset();
		GameUI_reset();
		MemHack_reset();
	}

	clearConsole();
}

//----------------------------------------------------------

BOOL startLua() {
	destroyMainState();

	lua_State* l = getMainState();
	HANDLE war3luaScript;
	BOOL result = 0;

	if (SFileOpenFileEx(*pMapMpq, "war3map.lua", NULL, &war3luaScript)) {
		SFileCloseFile(war3luaScript);

		lua_getglobal(l, "require");
		lua_pushstring(l, "war3map");
		if (!(result = !lua_pcall(l, 1, LUA_MULTRET, NULL))) {
			lua_throwerr(l);
		}

		lua_pop(l, 1);
	}

	return result;
}

BOOL __stdcall startLuaThread(DWORD esi) {
	PJASS_STACK stack = *(PJASS_STACK*)(esi + 0x2868);

	lua_State* l = (lua_State*)stack->pop()->value;
	getFunctionByRef(l, stack->pop()->value);
	UINT objectHandle = stack->pop()->value;
	lua_State* thread = getThreadState(l, -1);
	lua_xmove(l, thread, 1);

	int res;
	//lua_pushcfunction(l, stacktrace);
	switch (lua_resume(thread, l, 0, &res)) { /*lua_resume(thread, l, 0, &res) */
	case LUA_OK:
		((PJASS_DATA_SLOT)(esi + 80))->set(lua_toboolean(thread, 1), OPCODE_VARIABLE_BOOLEAN);

		break;
	case LUA_ERRRUN:
		UINT object = GetTriggerByHandle(objectHandle) | GetTimerByHandle(objectHandle) | GetGroupByHandle(objectHandle);

		if (object) {
			((UINT(__fastcall*)(UINT))(*(UINT*)(*(UINT*)object + 0x5c)))(object);
		}

		lua_throwerr(thread);

		return FALSE;
	}

	return TRUE;
}

//----------------------------------------------------------

void lua_throwerr(lua_State* l) {
	luaL_traceback(l, l, lua_tostring(l, -1), 0);
	LPCSTR error = lua_tostring(l, -1);
	lua_pop(l, 1);

	printf("\n%s--------------------Lua Error--------------------%s\n%s\n%s-------------------------------------------------%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, error, ANSI_COLOR_RED, ANSI_COLOR_RESET);
	printfChat(100, "\n|cFFFF0000--------------------Lua Error--------------------|r\n%s\n|cFFFF0000------------------------------------------------------------|r\n\n", error);
}

int stacktrace(lua_State* L) {
	luaL_traceback(L, L, lua_tostring(L, -1), 0);

	return 1;
}

//----------------------------------------------------------

lua_State* getThreadState(lua_State* l, int index) {
	lua_pushvalue(l, index);
	getGlobalTable(l, "_LUA_THREADS", false);
	lua_pushvalue(l, -2);

	if (lua_rawget(l, -2) != LUA_TTHREAD) {
		lua_pop(l, 1);
		lua_newthread(l);
		lua_pushvalue(l, -3);
		lua_pushvalue(l, -2);
		lua_rawset(l, -4);
	}

	lua_State* thread = lua_tothread(l, -1);
	lua_pop(l, 3);

	return thread;
}

BOOL getGlobalTable(lua_State* l, LPCSTR name, bool weak) {
	lua_getfield(l, LUA_REGISTRYINDEX, name);

	if (!lua_istable(l, -1)) {
		lua_pop(l, 1);
		lua_newtable(l);

		if (weak) {
			lua_newtable(l);
			lua_pushstring(l, "__mode");
			lua_pushstring(l, "kv");
			lua_rawset(l, -3);

			lua_setmetatable(l, -2);
		}

		lua_pushvalue(l, -1);
		lua_setfield(l, LUA_REGISTRYINDEX, name);

		return FALSE;
	}

	return TRUE;
}

int pushFunctionRef(lua_State* l, int index) {
	lua_pushvalue(l, index);
	getGlobalTable(l, "_LUA_FUNCTIONS_REF", false);

	int ref = (int)lua_rawlen(l, -1);
	lua_pushvalue(l, -2);
	lua_rawseti(l, -2, ++ref);

	lua_pop(l, 2);

	return ref;
}

void getFunctionByRef(lua_State* l, int ref) {
	getGlobalTable(l, "_LUA_FUNCTIONS_REF", false);
	lua_rawgeti(l, -1, ref);
	lua_remove(l, -2);
}