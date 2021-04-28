#pragma once

#include <Windows.h>
#include <lua.hpp>
#pragma comment(lib, "lua-5.4.3.lib")
#include <vector>

#include "Mem.h"

static HMODULE hGame = GetModuleHandle("game.dll");
static DWORD _GetTrigger = 0x44b6ae;
static DWORD _Main = 0x3b0a90;
static DWORD _MainProc = 0x3b54b0;
static DWORD _MapMPQ = 0xaae788;

extern lua_State* g_Lua;

enum TYPES {
	LUA_TRIGGER_CODE,
	LUA_CONDITION_CODE
};

typedef struct {
	lua_State* lua;
	lua_State* parent;
	TYPES type;
} LUA_TRIGGER, *PLUA_TRIGGER;

extern std::vector<PLUA_TRIGGER> g_LuaTriggers;