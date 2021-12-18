#pragma once

#include <Windows.h>
#include <map>

#include "fcalls.h"
#include "JassNatives.h"
#include "JassMachine.h"

#define WAR3_LUA_MAJOR "1"
#define WAR3_LUA_MINOR "1"
#define WAR3_LUA_RELEASE "3 (Beta)"

#define WAR3_LUA_VERSION WAR3_LUA_MAJOR "." WAR3_LUA_MINOR "." WAR3_LUA_RELEASE
#define WAR3_LUA "War3 Lua " WAR3_LUA_VERSION

#define MakePtr(a, b) ((DWORD)a + (DWORD)b)

static HMODULE gameBase = GetModuleHandle("game.dll");

enum OFFSETS {
	_mapMPQ = 0xaae788,
	_jassEntryPoint = 0x3b0a90,
	_jassEntryPointProc = 0x3b54b0,
	_getInstanceProc = 0x4c34d0,
	_overflowOpcodeProc = 0x45f79a,
	_opcodeList = 0x45f808,
	_opcodeListSize = 0x45ea4d,
	_opcodeSwitch = 0x45ea5a,
	_jassNativesList = 0x3d4025,
	_getGameUI = 0x300710,
	_getGameWar3 = 0x75f0
};

extern std::map<LPCSTR, JASSNATIVE> jassnatives;
extern std::map<DWORD, JASS_OPLIST> triggers;