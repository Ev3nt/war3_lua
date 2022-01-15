#include "LuaMachine.h"
#include "LuaFunctions.h"
#include "LuaHooks.h"
#include "JassMachine.h"
#include "JassNatives.h"
#include "GameUI.h"
#include "Utils.h"
#include "Global.h"
#include <Storm.h>

lua_State* mainState;
bool running = false;

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
		lua_openJassNatives(l);
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
		running = false;

		JassNatives_reset();
		GameUI_reset();
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

		running = true;

		lua_pushcfunction(l, stacktrace);
		lua_getglobal(l, "require");
		lua_pushstring(l, "war3map");
		if (!(result = !lua_pcall(l, 1, LUA_MULTRET, -3))) {
			lua_throwerr(l);
		}

		lua_pop(l, 1);
	}

	return result;
}

BOOL __stdcall startLuaThread(DWORD esi) {
	if (!running) {
		return FALSE;
	}

	PJASS_STACK stack = *(PJASS_STACK*)(esi + 0x2868);

	lua_State* l = (lua_State*)stack->pop()->value;
	getFunctionByRef(l, stack->pop()->value);
	lua_State* thread = getThreadState(l, -1);
	lua_xmove(l, thread, 1);

	int res;
	switch (lua_resume(thread, l, 0, &res)) {
	case LUA_OK:
		((PJASS_DATA_SLOT)(esi + 80))->set(lua_toboolean(thread, 1), OPCODE_VARIABLE_BOOLEAN);

		break;
	case LUA_ERRRUN:
		lua_throwerr(thread);

		return FALSE;
	}

	return TRUE;
}

//----------------------------------------------------------

void lua_throwerr(lua_State* l) {
	LPCSTR error = lua_tostring(l, -1);
	running = false;

	printf("--------------------Lua Error--------------------\n%s\n-------------------------------------------------\n\n", error);
	MessageBox(NULL, error, "Lua Error", MB_ICONHAND | MB_TOPMOST);
}

int stacktrace(lua_State* L)
{
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