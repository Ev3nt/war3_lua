#pragma once

#ifndef PCH_H
#define PCH_H
#include <Windows.h>
#include <cstddef>
#include <detours.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <lua.hpp>
#include <iostream>
#include <map>
#include "fp_call.h"

#define ANSI_COLOR_RED     "\x1B[31m"
#define ANSI_COLOR_GREEN   "\x1B[32m"
#define ANSI_COLOR_YELLOW  "\x1B[33m"
#define ANSI_COLOR_BLUE    "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN    "\x1B[36m"
#define ANSI_COLOR_RESET   "\x1B[0m"

#define WAR3_LUA_MAJOR "1"
#define WAR3_LUA_MINOR "1"
#define WAR3_LUA_RELEASE "7"
#define WAR3_LUA_VERSION_NAME  ANSI_COLOR_YELLOW "Outland" ANSI_COLOR_RESET

#define WAR3_LUA_VERSION WAR3_LUA_MAJOR "." WAR3_LUA_MINOR "." WAR3_LUA_RELEASE
#define WAR3_LUA "War3 Lua " WAR3_LUA_VERSION

#define GAME_ID "W3L"

static HMODULE gameBase = GetModuleHandle("game.dll");
static HANDLE* pMapMpq = (HANDLE*)((std::ptrdiff_t)gameBase + 0xaae788);

extern bool developerMode;

extern SYSTEMTIME date;
#endif