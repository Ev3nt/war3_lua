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

	void lua_throwWarning(lua_State* l, std::string msg);

	int stacktrace(lua_State* L);

	//----------------------------------------------------------

	lua_State* GetMainState(bool init) {
		if (!mainState && init) {
			lua_State* l = mainState = luaL_newstate();
			luaL_openlibs(l);
			LuaHooks::lua_replaceSearchers(l);
			LuaHooks::lua_replaceGlobals(l);

			if (!developerMode) {
				LuaHooks::lua_disableFunctions(l);
				LuaHooks::lua_replaceFileStreamFunctions(l);
			}

			LuaFunctions::lua_openJassNatives(l);
			LuaFunctions::lua_openExternalFunctions(l);
			LuaFunctions::lua_openJassVariables(l);
		}

		return mainState;
	}

	void DestroyLua() {
		if (mainState) {
			lua_close(mainState);
			mainState = NULL;
			Jass::JassOpcodesReset();
			Jass::JassNativesReset();
			LuaMachine::HandleMetatablesReset();
		}

		Logger::ClearConsole();
	}

	void StartLua() {
		lua_State* l = GetMainState();
		Storm::Archive map;
		map.Connect(*(HANDLE*)pOffsets[(UINT)Offset::LastPlayedMap]);
		if (!map["war3map.lua"].empty()) {
			lua_pushcfunction(l, stacktrace);
			lua_getglobal(l, "require");
			lua_pushstring(l, "war3map");
			if (lua_pcall(l, 1, LUA_MULTRET, -3) != LUA_OK) {
				lua_throwerr(l);
			}

			lua_pop(l, lua_gettop(l));
		}
	}

	BOOL __stdcall StartLuaThread() {
		JassMachine::PJASS_INSTANCE JassVM = JassMachine::GetJassInstance();
		JassMachine::PJASS_STACK stack = JassVM->stack;
		BOOL result = TRUE;

		lua_State* l = (lua_State*)stack->Pop()->value; //GetMainState();
		lua_State* thread = lua_newthread(l);
		GetFunctionByRef(thread, stack->Pop()->value);

		if (!lua_isfunction(thread, -1)) {
			lua_pushfstring(thread, "Couldn't start the thread. Expected type function, got %s (stack size %d). Contact me at XGM or VK.", lua_typename(l, lua_type(thread, -1)), lua_gettop(thread));
			lua_remove(thread, -2);

			goto Error;
		}

		int res;
		switch (lua_resume(thread, l, 0, &res)) {
		case LUA_OK:
			JassVM->condition_return_value.Set(lua_toboolean(thread, 1), OPCODE_VARIABLE::TYPE_BOOLEAN);

			break;
		case LUA_ERRRUN:
		Error:
			UINT index = Jass::GetNative("GetTriggeringTrigger").Invoke(NULL, NULL);
			if (!index) {
				index = Jass::GetNative("GetExpiredTimer").Invoke(NULL, NULL);
			}

			PVOID handle = Warcraft::ConvertHandle(index);
			if (handle) {
				fast_call<UINT>((*(UINT*)(*(UINT*)handle + 0x5c)), handle);
			}

			stacktrace(thread);
			lua_remove(thread, -2);
			lua_throwerr(thread);

			result = FALSE;
		}

		lua_pop(l, lua_gettop(l)); // It should be there, cause gc can dealloc the thread, before code has been done.

		return result;
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

	int GetUserdataByHandle(lua_State* l, DWORD handle, LPCSTR tname) {
		if (!handle) {
			lua_pushnil(l);

			return 1;
		}

		UINT key = (UINT)Warcraft::ConvertHandle(handle);
		key ? GetGlobalTable(l, "_LUA_WARCRAFT_HANDLES", false) : (GetGlobalTable(l, std::string("_LUA_CONST_").append(tname).c_str(), false), key = handle);
		lua_pushinteger(l, key);
		lua_rawget(l, -2);

		if (luaL_testudata(l, -1, tname)) {
			lua_remove(l, -2);

			return 1;
		}
		else if (lua_isnil(l, -1)) {
			lua_pop(l, 1);
			*(DWORD*)lua_newuserdata(l, sizeof(handle)) = handle;
			lua_pushinteger(l, key);
			lua_pushvalue(l, -2);
			lua_rawset(l, -4);
			lua_remove(l, -2);
		}

		luaL_setmetatable(l, tname);

		return 1;
	}

	void DeleteUserdataByHandle(lua_State* l, DWORD handle) {
		GetGlobalTable(l, "_LUA_WARCRAFT_HANDLES", false);
		lua_pushinteger(l, handle);
		lua_rawget(l, -2);

		if (!lua_isnil(l, -1)) {
			*(DWORD*)lua_touserdata(l, -1) = NULL;
			lua_pushinteger(l, handle);
			lua_pushnil(l);
			lua_rawset(l, -4);
		}

		lua_pop(l, 2);
	}

	//----------------------------------------------------------

	void lua_throwerr(lua_State* l) {
		std::string error = lua_tostring(l, -1);
		Logger::Log(error, Logger::LEVEL::LOG_ERROR);
		Warcraft::PrintChat(Utils::format("[|cFFFF0000Error|r] %s", error).c_str(), 100);
	}

	void lua_throwWarning(lua_State* l, std::string msg) {
		luaL_traceback(l, l, msg.c_str(), 0);
		std::string warning = lua_tostring(l, -1);
		lua_pop(l, 1);

		Logger::Log(warning, Logger::LEVEL::LOG_WARNING);
		Warcraft::PrintChat(Utils::format("[|cFFC19C00Warning|r] %s", warning).c_str(), 100);
	}

	int stacktrace(lua_State* L) {
		luaL_traceback(L, L, lua_tostring(L, -1), 0);

		return 1;
	}

	//----------------------------------------------------------

	std::map<std::string, bool> handlemetatypes;
}