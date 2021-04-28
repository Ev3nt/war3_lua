#pragma once

#include <Windows.h>
#include <Storm.h>
#pragma comment(lib, "storm.lib")

#include "Variables.h"
#include "LuaRegister.h"

void ClearScreen();

void RunLua()
{
	if (g_Lua)
	{
		lua_close(g_Lua);

		for (const auto& trigger : g_LuaTriggers)
			delete trigger;

		std::vector<PLUA_TRIGGER>().swap(g_LuaTriggers);
	}

	ClearScreen();

	g_Lua = luaL_newstate();

	luaL_openlibs(g_Lua);

	lua_opencfunctions(g_Lua);
	
	HANDLE hMapMPQ = *(HANDLE*)MakePtr(hGame, _MapMPQ);
	if (hMapMPQ)
	{
		HANDLE hFile;
		if (SFileOpenFileEx(hMapMPQ, "war3map.lua", NULL, &hFile))
		{
			int lenght = 65535;
			char* buffer = new char[lenght];
			ZeroMemory(buffer, lenght);

			SFileReadFile(hFile, buffer, lenght, NULL, NULL);
			if (luaL_loadstring(g_Lua, buffer))
				printf("[LUA] Couldn't load war3map.lua.\n");
			else
				if (lua_pcall(g_Lua, 0, LUA_MULTRET, 0))
					printf("[LUA] Syntax error.\n");
				else
					printf("[LUA] Successfully!\n");

			delete[] buffer;

			SFileCloseFile(hFile);
		}
		else
			printf("[LUA] war3map.lua doesn't exist.\n");
	}
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
		return;

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
		return;

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count))
		return;

	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count))
		return;

	SetConsoleCursorPosition(hStdOut, homeCoords);
}