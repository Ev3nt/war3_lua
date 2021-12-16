#pragma once

#include <Windows.h>

#include <lua.hpp>
#pragma comment(lib, "lua.lib")

typedef int LUA;

lua_State* getMainLuaState();

void destroyMainLuaState();

lua_State* getMainThread(lua_State* thread);

BOOL getGlobalTable(lua_State* l, LPCSTR name, bool weak);

int pushFunctionRef(lua_State* l, int index);

void getFunctionByRef(lua_State* l, int ref);

DWORD startLua();

BOOL CALLBACK startLuaThread(DWORD esi, DWORD edi);