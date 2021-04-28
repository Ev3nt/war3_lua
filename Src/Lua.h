#pragma once

#include <Windows.h>

#include "Variables.h"
#include "LuaRegister.h"

void RunLua()
{
	if (g_Lua)
	{
		lua_close(g_Lua);

		for (const auto& trigger : g_LuaTriggers)
			delete trigger;

		std::vector<PLUA_TRIGGER>().swap(g_LuaTriggers);
	}

	system("cls");

	g_Lua = luaL_newstate();

	luaL_openlibs(g_Lua);

	lua_opencfunctions(g_Lua);

	if (luaL_dofile(g_Lua, "scripts/blizzard.lua"))
		printf("Lua isn't loaded(((((\n");
}