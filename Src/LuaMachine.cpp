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
			if (lua_pcall(l, 1, 0, -3) != LUA_OK) {
				lua_throwerr(l);
				lua_pop(l, 1);
			}

			lua_pop(l, 1);
		}
	}

	BOOL __stdcall StartLuaThread() {
		JassMachine::PJASS_INSTANCE JassVM = JassMachine::GetJassInstance();
		JassMachine::PJASS_STACK stack = JassVM->stack;
		BOOL result = TRUE;

		lua_State* l = GetMainState(false);
		GetFunctionByKey(l, stack->Pop()->value);
		GetGlobalTable(l, "_LUA_THREADS", true, false);
		lua_pushvalue(l, -2);
		if (lua_rawget(l, -2) != LUA_TTHREAD) {
			lua_pop(l, 1);
			lua_newthread(l);
			lua_pushvalue(l, -3);
			lua_pushvalue(l, -2);
			lua_rawset(l, -4);
		}
		lua_State* thread = lua_tothread(l, -1);
		lua_pop(l, 2);
		lua_xmove(l, thread, 1);

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

		return result;
	}

	//----------------------------------------------------------

	void HandleMetatablesReset() {
		LuaMachine::handlemetatypes.clear();
	}

	BOOL GetGlobalTable(lua_State* l, LPCSTR name, bool weakKey, bool weakValue) {
		lua_getfield(l, LUA_REGISTRYINDEX, name);

		if (!lua_istable(l, -1)) {
			lua_pop(l, 1);
			lua_newtable(l);

			BYTE weak = (weakValue << 1) | (BYTE)weakKey;
			if (weak) {
				LPCSTR mode;
				lua_newtable(l);

				switch (weak)
				{
				case 1:
					mode = "k";

					break;
				case 2:
					mode = "v";

					break;
				default:
					mode = "kv";
				}

				lua_pushstring(l, mode);

				lua_setfield(l, -2, "__mode");

				lua_setmetatable(l, -2);
			}

			lua_pushvalue(l, -1);
			lua_setfield(l, LUA_REGISTRYINDEX, name);

			return FALSE;
		}

		return TRUE;
	}

	DWORD PushFunctionByKey(lua_State* l, int index, DWORD key) {
		GetGlobalTable(l, "_LUA_CALLBACKS", false, true);

		lua_pushvalue(l, index);
		lua_rawseti(l, -2, key);

		lua_pop(l, 1);

		return key;
	}

	void GetFunctionByKey(lua_State* l, DWORD key) {
		GetGlobalTable(l, "_LUA_CALLBACKS", false, true);
		lua_rawgeti(l, -1, key);
		lua_remove(l, -2);
	}

	int GetUserdataByHandle(lua_State* l, DWORD handle, LPCSTR tname) {
		if (!handle) {
			lua_pushnil(l);

			return 1;
		}

		UINT key = (UINT)Warcraft::ConvertHandle(handle);
		if (key) {
			GetGlobalTable(l, "_LUA_WARCRAFT_HANDLES", false, false);
		}
		else {
			GetGlobalTable(l, std::string("_LUA_CONST_").append(tname).data(), false, false);
			key = handle;
		}
		lua_rawgeti(l, -1, key);

		if (luaL_testudata(l, -1, tname)) {
			lua_remove(l, -2);

			return 1;
		}
		else if (lua_isnil(l, -1)) {
			lua_pop(l, 1);
			*(DWORD*)lua_newuserdata(l, sizeof(handle)) = handle;
			lua_pushvalue(l, -1);
			lua_rawseti(l, -3, key);
			lua_remove(l, -2);
		}

		luaL_setmetatable(l, tname);

		return 1;
	}

	void DeleteUserdataByHandle(lua_State* l, DWORD handle) {
		GetGlobalTable(l, "_LUA_WARCRAFT_HANDLES", false, false);

		if (lua_rawgeti(l, -1, handle) != LUA_TNIL) {
			*(DWORD*)lua_touserdata(l, -1) = NULL; // 2
			lua_pushnil(l); // 3
			lua_rawseti(l, -3, handle); // 2
		}

		lua_pop(l, 2);
	}

	//----------------------------------------------------------

	void lua_throwerr(lua_State* l) {
		std::string error = lua_tostring(l, -1);
		Warcraft::PrintChat((Logger::Log(error, Logger::LEVEL::LOG_ERROR) + error).data(), 100);
	}

	void lua_throwWarning(lua_State* l, std::string msg) {
		luaL_traceback(l, l, msg.data(), 0);
		std::string warning = lua_tostring(l, -1);
		lua_pop(l, 1);

		Warcraft::PrintChat((Logger::Log(warning, Logger::LEVEL::LOG_WARNING) + warning).data(), 100);
	}

	int stacktrace(lua_State* L) {
		luaL_traceback(L, L, lua_tostring(L, -1), 0);

		return 1;
	}

	//----------------------------------------------------------

	std::map<std::string, bool> handlemetatypes;
}