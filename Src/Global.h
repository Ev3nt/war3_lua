#pragma once

#include <Windows.h>

#define ANSI_COLOR_RED     "\x1B[31m"
#define ANSI_COLOR_GREEN   "\x1B[32m"
#define ANSI_COLOR_YELLOW  "\x1B[33m"
#define ANSI_COLOR_BLUE    "\x1B[34m"
#define ANSI_COLOR_MAGENTA "\x1B[35m"
#define ANSI_COLOR_CYAN    "\x1B[36m"
#define ANSI_COLOR_RESET   "\x1B[0m"

#define WAR3_LUA_MAJOR "1"
#define WAR3_LUA_MINOR "1"
#define WAR3_LUA_RELEASE "4"
#define WAR3_LUA_VERSION_NAME  ANSI_COLOR_GREEN "Ashenvale" ANSI_COLOR_RESET

#define WAR3_LUA_VERSION WAR3_LUA_MAJOR "." WAR3_LUA_MINOR "." WAR3_LUA_RELEASE
#define WAR3_LUA "War3 Lua " WAR3_LUA_VERSION

#define GAME_ID "W3L"

static HMODULE gameBase = GetModuleHandle("game.dll");
static HWND gameWindow = FindWindow(NULL, "Warcraft III");

static HANDLE* pMapMpq = (HANDLE*)((UINT_PTR)gameBase + 0xaae788);

extern bool consoleMode;
extern bool developerMode;