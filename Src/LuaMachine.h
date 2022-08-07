#pragma once

namespace LuaMachine {
	extern std::map<std::string, bool> handlemetatypes;

	void DestroyLua();
	void StartLua();
	BOOL __stdcall StartLuaThread();

	void HandleMetatablesReset();
	BOOL GetGlobalTable(lua_State* l, LPCSTR name, bool weak);

	int PushFunctionRef(lua_State* l, int index);
	void GetFunctionByRef(lua_State* l, int ref);
}