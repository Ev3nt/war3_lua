#include "pch.h"
#include "LuaMachine.h"
#include "JassMachine.h"
#include "EasyStormLib/EasyStormLib.h"
#include "JassNatives.h"
#include "LuaHooks.h"
#include "LuaFunctions.h"
#include "Logger.h"

namespace LuaMachine {
	lua_State* mainState = NULL;

	void lua_throwerr(lua_State* l);

	int stacktrace(lua_State* L);

	//----------------------------------------------------------

	lua_State* GetMainState() {
		if (!mainState) {
			lua_State* l = mainState = luaL_newstate();
			luaL_openlibs(l);
			LuaHooks::lua_replaceSearchers(l);
			LuaHooks::lua_replaceGlobals(l);

			if (!developerMode) {
				LuaHooks::lua_disableFunctions(l);
				LuaHooks::lua_replaceFileStreamFunctions(l);
			}

			LuaFunctions::lua_openJassNatives(l);
		}

		return mainState;
	}

	void DestroyLua() {
		if (mainState) {
			lua_close(mainState);
			mainState = NULL;
			Jass::JassOpcodesReset();
		}

		Logger::ClearConsole();
	}


	void StartLua() {
		DestroyLua();

		lua_State* l = GetMainState();
		Storm::Archive map;
		map.Connect(*pMapMpq);
		if (!map["war3map.lua"].empty()) {
			lua_pushcfunction(l, stacktrace);
			lua_getglobal(l, "require");
			lua_pushstring(l, "war3map");
			if (lua_pcall(l, 1, LUA_MULTRET, -3) != LUA_OK) {
				lua_throwerr(l);
			}

			lua_pop(l, 2);
		}
	}

	BOOL __stdcall StartLuaThread() {
		JassMachine::PJASS_INSTANCE JassVM = JassMachine::GetJassInstance();
		JassMachine::PJASS_STACK stack = JassVM->stack;

		lua_State* l = GetMainState();
		lua_State* thread = lua_newthread(l);
		GetFunctionByRef(thread, stack->Pop()->value);
		lua_pop(l, 1);

		if (!lua_isfunction(thread, -1)) {
			lua_pop(thread, 1);
			lua_pushstring(thread, "Couldn't start the thread. Write to me at XGM or VK.");

			goto Error;
		}

		int res;
		switch (lua_resume(thread, l, 0, &res)) {
		case LUA_OK:
			JassVM->condition_return_value.Set(lua_toboolean(thread, 1), JassMachine::OPCODE_VARIABLE_BOOLEAN);


			break;
		case LUA_ERRRUN:
			Error:
			PVOID handle = ConvertHandle(Jass::GetNative("GetTriggeringTrigger").Invoke(NULL, NULL) | Jass::GetNative("GetExpiredTimer").Invoke(NULL, NULL));

			if (handle) {
				fast_call<UINT>((*(UINT*)(*(UINT*)handle + 0x5c)), handle);
			}

			lua_throwerr(thread);

			return FALSE;
		}

		return TRUE;
	}

	//----------------------------------------------------------

	void HandleMetatablesReset() {
		std::map<std::string, bool>().swap(LuaMachine::handlemetatypes);
	}

	BOOL GetGlobalTable(lua_State* l, LPCSTR name, bool weak) {
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

	int PushFunctionRef(lua_State* l, int index) {
		lua_pushvalue(l, index); // 1 +
		GetGlobalTable(l, "_LUA_FUNCTIONS_REF", false); // 2 +

		int ref = (int)lua_rawlen(l, -1);
		lua_pushvalue(l, -2); // 3 +
		lua_rawseti(l, -2, ++ref); // 2 -

		lua_pop(l, 2); // 0 -

		return ref;
	}

	void GetFunctionByRef(lua_State* l, int ref) {
		GetGlobalTable(l, "_LUA_FUNCTIONS_REF", false); // 1 +
		lua_rawgeti(l, -1, ref); //  2 +
		lua_remove(l, -2); // 1 -
	}

	//----------------------------------------------------------

	void lua_throwerr(lua_State* l) {
		std::string error = lua_tostring(l, -1);
		Logger::Log(Logger::LOG_LEVEL::LOG_ERROR, error.c_str());
		PrintfChat(100, "\n[|cFFFF0000Error|r] %s\n\n", error.c_str());
		//printf("\n%s--------------------Lua Error--------------------%s\n%s\n%s-------------------------------------------------%s\n\n", ANSI_COLOR_RED, ANSI_COLOR_RESET, error, ANSI_COLOR_RED, ANSI_COLOR_RESET);
		//printfChat(100, "\n|cFFFF0000--------------------Lua Error--------------------|r\n%s\n|cFFFF0000------------------------------------------------------------|r\n\n", error);
	}

	int stacktrace(lua_State* L)
	{
		luaL_traceback(L, L, lua_tostring(L, -1), 0);

		return 1;
	}

	//----------------------------------------------------------

	std::map<std::string, bool> handlemetatypes;
}