#pragma once

#include <Windows.h>
#include <map>
#include <unordered_map>

#include "fcalls.h"
#include "JassNatives.h"
#include "JassMachine.h"
#include "FrameAPI.h"

#define WAR3_LUA_MAJOR "1"
#define WAR3_LUA_MINOR "1"
#define WAR3_LUA_RELEASE "4 (Beta)"

#define WAR3_LUA_VERSION WAR3_LUA_MAJOR "." WAR3_LUA_MINOR "." WAR3_LUA_RELEASE
#define WAR3_LUA "War3 Lua " WAR3_LUA_VERSION

#define GAME_ID "W3L"

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

	_getWarcraftID1 = 0x54f248,
	_getWarcraftID2 = 0x54f24f,

	_netProvider = 0xacec10,

	_getGameUI = 0x300710,
	_getGameWar3 = 0x75f0,
	_getTooltipFrame = 0x337240,

	_stringHastTable = 0xacd214,
	_FDFHashTable = 0xacd264,
	_stringHashNodeGrowListArray = 0x5ca9b0,
	_baseFrameHashNodeGrowListArray = 0x5d5650,
	_readFDFFile = 0x5d8de0,
	_CFrameDefStatus = 0xa8c804,
	_getCFrameByName = 0x5fa970,
	_createCFrame = 0x5c9560,
	_setCFrameText = 0x611d40,
	_setCFrameTextColor = 0x611590,
	_getCFrameTextHeight = 0x6118a0,
	// _getCLayoutFrameWidth = 0x604fb0,
	// _getCLayoutFrameHeight = 0x604fa0,
	_setCLayoutFrameScale = 0x605d40,
	_setCLayoutFramePoint = 0x606770,
	_clearCLayoutFrameAllPoints = 0x606270,
	_setCLayoutFrameWidth = 0x605d90,
	_setCLayoutFrameHeight = 0x605db0,
	_setCLayoutFrameAbsolutePoint = 0x6061b0,
	_setCLayoutFrameCageMouse = 0x604fc0,
	_setCLayoutFrameAllPoints = 0x6067f0,

	_frameevent_control_click = 0xa9a86c,
	_frameevent_control_mouseenter = 0xa9a84c
};

extern std::map<LPCSTR, JASSNATIVE> jassnatives;
extern std::map<DWORD, JASS_OPLIST> triggers;
extern std::unordered_map<EFrameEvent, std::unordered_map<UINT, UINT>> frameEventHashTable;
extern bool running;