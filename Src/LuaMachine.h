#pragma once

#include <Windows.h>

#include <lua.hpp>
#pragma comment(lib, "lua-5.4.3.lib")

typedef int LUA;

void lua_preload(lua_State* l, LPCSTR name, lua_CFunction function);

lua_State* GetMainLuaState();

void DestroyMainLuaState();

lua_State* GetMainThread(lua_State* thread);

void GetGlobalTable(lua_State* l, LPCSTR name, bool weak);

int PushFunctionRef(lua_State* l, int index);

void GetFunctionByRef(lua_State* l, int ref);

void StartLua();

BOOL CALLBACK StartLuaThread(DWORD esi, DWORD edi);