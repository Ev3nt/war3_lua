#pragma once

#include <Windows.h>
#include <lua.hpp>

extern bool running;

BOOL startLua();

BOOL __stdcall startLuaThread(DWORD esi);

lua_State* getThreadState(lua_State* l, int index);

BOOL getGlobalTable(lua_State* l, LPCSTR name, bool weak);

int pushFunctionRef(lua_State* l, int index);

void getFunctionByRef(lua_State* l, int ref);