#pragma once

#include <Windows.h>
#include <map>

#include "JassNatives.h"
#include "JassMachine.h"

#define WAR3_LUA_MAJOR "1"
#define WAR3_LUA_MINOR "1"
#define WAR3_LUA_RELEASE "1"

#define WAR3_LUA_VERSION WAR3_LUA_MAJOR "." WAR3_LUA_MINOR "." WAR3_LUA_RELEASE
#define WAR3_LUA "War3 Lua " WAR3_LUA_VERSION

static HMODULE hGame = GetModuleHandle("game.dll");
static DWORD _MapMPQ = 0xaae788;
static DWORD _JassEntryPoint = 0x3b0a90;
static DWORD _JassEntryPointProc = 0x3b54b0;
static DWORD _GetInstanceProc = 0x4c34d0;
static DWORD _OverflowOpcodeProc = 0x45f79a;
static DWORD _OpcodeList = 0x45f808;
static DWORD _OpcodeListSize = 0x45ea4d;
static DWORD _OpcodeSwitch = 0x45ea5a;
static DWORD _JassNativesList = 0x3d4025;

extern std::map<LPCSTR, JASSNATIVE> jassnatives;
extern std::map<DWORD, JASS_OPLIST> triggers;