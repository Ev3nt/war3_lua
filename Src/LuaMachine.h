#pragma once

namespace LuaMachine {
	extern std::map<std::string, bool> handlemetatypes;

	lua_State* GetMainState(bool init = true);

	void DestroyLua();
	void StartLua();
	BOOL __stdcall StartLuaThread();

	void HandleMetatablesReset();
	BOOL GetGlobalTable(lua_State* l, LPCSTR name, bool weak);

	int PushFunctionRef(lua_State* l, int index);
	void GetFunctionByRef(lua_State* l, int ref);

	BOOL GetUserdataByHandle(lua_State* l, DWORD handle, LPCSTR tname);
	void DeleteUserdataByHandle(lua_State* l, DWORD handle);
}