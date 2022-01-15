#pragma once

#include <Windows.h>

#include <lua.hpp>
#pragma comment(lib, "lua.lib")

typedef int LUA;

lua_State* getMainLuaState();

void destroyMainLuaState();

lua_State* getMainThread(lua_State* thread);

lua_State* createThread(lua_State* l, int index);

void lua_throwerr(lua_State* l);

BOOL getGlobalTable(lua_State* l, LPCSTR name, bool weak);

int pushFunctionRef(lua_State* l, int index);

void getFunctionByRef(lua_State* l, int ref);

DWORD startLua();

BOOL CALLBACK startLuaThread(DWORD esi, DWORD edi);