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
#include "Detours.h"
#include "fp_call.h"
#include "Utils.h"

#define WAR3_LUA_VERSION_COLOR "|cFF53377A"
#define WAR3_LUA_VERSION_COLOR_RESET "|r"

#define WAR3_LUA_MAJOR "1"
#define WAR3_LUA_MINOR "3"
#define WAR3_LUA_RELEASE "7"
#define WAR3_LUA_VERSION_NAME  WAR3_LUA_VERSION_COLOR "Blight" WAR3_LUA_VERSION_COLOR_RESET

#define WAR3_LUA_VERSION WAR3_LUA_MAJOR "." WAR3_LUA_MINOR "." WAR3_LUA_RELEASE
#define WAR3_LUA "War3 Lua " WAR3_LUA_VERSION

#define GAME_ID "W3L"

static HMODULE gameBase = GetModuleHandle("game.dll");

extern bool developerMode;
extern bool disableWarnings;
#endif