#pragma once

#include <Windows.h>
#include <lua.hpp>

void lua_openJassNatives(lua_State* l);

void lua_openMemHackAPI(lua_State* l);

void lua_openFrameAPI(lua_State* l);