#include "LuaMachine.h"

#include <fstream>
#include <Storm.h>
#pragma comment(lib, "storm.lib")

#include "Variables.h"
#include "LuaRegister.h"
#include "Warcraft.h"
#include "Mem.h"

lua_State* MainLuaState = NULL;

void lua_preload(lua_State* l, LPCSTR name, lua_CFunction function)
{
	lua_getfield(l, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);
	lua_pushcclosure(l, function, 0);
	lua_setfield(l, -2, name);
	lua_pop(l, 1);
}

//-----------------------------------------------------------------------------

static int checkload(lua_State* L, int stat, const char* filename) {
	if (stat) {
		lua_pushstring(L, filename);
		return 2;
	}
	else
		return luaL_error(L, "error loading module '%s' from file '%s':\n\t%s",
			lua_tostring(L, 1), filename, lua_tostring(L, -1));
}

static int searcher_LuaInMpq(lua_State* l) {
	HANDLE map = *(HANDLE*)MakePtr(hGame, _MapMPQ);

	std::string filename = luaL_checkstring(l, 1) + std::string(".lua");
	lua_pop(l, 1);

	HANDLE file;
	if (SFileOpenFileEx(map, filename.c_str(), NULL, &file)) {
		int lenght = SFileGetFileSize(file, NULL);
		char* buffer = new char[lenght + 1];
	
		ZeroMemory(buffer, lenght + 1);

		SFileReadFile(file, buffer, lenght, NULL, NULL);
		SFileCloseFile(file);

		int result = checkload(l, (luaL_loadstring(l, buffer) == LUA_OK), filename.c_str());
		delete[] buffer;
	
		return result;
	}

	char mapname[MAX_PATH] = { 0 };
	SFileGetArchiveName(map, mapname, sizeof(mapname));
	std::string mapnamestring = mapname;

	for (size_t i = mapnamestring.size(); i > 0; i--) {
		if (mapnamestring[i] == '\\') {
			mapnamestring = mapnamestring.substr(i + 1);

			break;
		}
	}
	

	lua_pushstring(l, std::string("no file '(" + mapnamestring + "):\\" + filename + "'").c_str());

	return 1;
}

//-----------------------------------------------------------------------------

lua_State* GetMainLuaState()
{
	if (!MainLuaState)
	{
		lua_State* l = MainLuaState = luaL_newstate();

		luaL_openlibs(l);
		lua_open_jassnatives(l);
		
		std::vector<lua_CFunction> searchers;

		lua_getglobal(l, "package");
		lua_getfield(l, -1, "searchers");

		lua_rawgeti(l, -1, 1);
		searchers.push_back(lua_tocfunction(l, -1));
		lua_pop(l, 1);
		
		// for (int i = 1; ; i++) {
		// 	if (lua_rawgeti(l, -1, i) == LUA_TNIL) {
		// 		lua_pop(l, 1);
		// 
		// 		break;
		// 	}
		// 
		// 	searchers.push_back(lua_tocfunction(l, -1));
		// 	lua_pop(l, 1);
		// }
		// 
		// searchers.pop_back();
		// searchers.pop_back();
		// 
		//searchers.insert(searchers.begin() + 1, searcher_LuaInMpq);

		searchers.push_back(searcher_LuaInMpq);

		for (size_t i = 0; i < searchers.size(); i++) {
			lua_pushvalue(l, -2);
			lua_pushcclosure(l, searchers[i], 1);
			lua_rawseti(l, -2, i + 1);
		}

		lua_pushnil(l);
		lua_rawseti(l, -2, 3);

		lua_pushnil(l);
		lua_rawseti(l, -2, 4);

		lua_pop(l, 2);
		std::vector<lua_CFunction>().swap(searchers);
	}

	return MainLuaState;
}

lua_State* CreateThread(lua_State* l, int index)
{
	lua_pushvalue(l, index);
	GetGlobalTable(l, "_LUA_THREADS", false);
	lua_pushvalue(l, -2);

	if (lua_rawget(l, -2) != LUA_TTHREAD)
	{
		lua_pop(l, 1);
		lua_newthread(l);
		lua_pushvalue(l, -3);
		lua_pushvalue(l, -2);
		lua_rawset(l, -4);
	}

	lua_State* thread = lua_tothread(l, -1);
	lua_pop(l, 3);

	return thread;
}

void ClearScreen()
{
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

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

void DestroyMainLuaState()
{
	if (MainLuaState)
	{
		lua_close(MainLuaState);
		MainLuaState = NULL;
		triggers.clear();
	}

	ClearScreen();
}

lua_State* GetMainThread(lua_State* thread)
{
	lua_rawgeti(thread, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
	lua_State* l = lua_tothread(thread, -1);
	lua_pop(thread, 1);

	return l;
}

void GetGlobalTable(lua_State* l, LPCSTR name, bool weak)
{
	lua_getfield(l, LUA_REGISTRYINDEX, name);

	if (!lua_istable(l, -1))
	{
		lua_pop(l, 1);
		lua_newtable(l);

		if (weak)
		{
			lua_newtable(l);
			lua_pushstring(l, "__mode");
			lua_pushstring(l, "kv");
			lua_rawset(l, -3);

			lua_setmetatable(l, -2);
		}

		lua_pushvalue(l, -1);
		lua_setfield(l, LUA_REGISTRYINDEX, name);
	}
}

int PushFunctionRef(lua_State* l, int index)
{
	lua_pushvalue(l, index);
	GetGlobalTable(l, "_LUA_FUNCTIONS_REF", false);

	int ref = (int)lua_rawlen(l, -1);
	lua_pushvalue(l, -2);
	lua_rawseti(l, -2, ++ref);

	lua_pop(l, 2);

	return ref;
}

void GetFunctionByRef(lua_State* l, int ref)
{
	GetGlobalTable(l, "_LUA_FUNCTIONS_REF", false);
	lua_rawgeti(l, -1, ref);
	lua_remove(l, -2);
}

void StartLua()
{
	DestroyMainLuaState();

	lua_State* l = GetMainLuaState();

	//luaL_dofile(l, ".\\Scripts\\main.lua");

	HANDLE hMapMPQ = *(HANDLE*)MakePtr(hGame, _MapMPQ);
	if (hMapMPQ)
	{
		HANDLE hFile;
		if (SFileOpenFileEx(hMapMPQ, "war3map.lua", NULL, &hFile))
		{
			int lenght = SFileGetFileSize(hFile, NULL);
			char* buffer = new char[lenght];

			ZeroMemory(buffer, lenght);

			SFileReadFile(hFile, buffer, lenght, NULL, NULL);
			SFileCloseFile(hFile);
			//lua_pushcfunction(g_Lua, traceback);
			if (luaL_loadstring(l, buffer))
				printf("[LUA] Failed to load war3map.lua.\n");
			else
				if (lua_pcall(l, 0, 0, 0))
				{
					printf("[LUA] Lua error.\n");
					printf("%s\n", lua_tostring(l, -1));
				}
				else
					printf("[LUA] Successfully!\n");

			delete[] buffer;
		}
	}
}

BOOL CALLBACK StartLuaThread(DWORD esi, DWORD edi)
{
	PJASS_STACK stack = (PJASS_STACK) * (DWORD*)(esi + 0x2868);

	lua_State* l = (lua_State*)stack->pop()->value;
	GetFunctionByRef(l, stack->pop()->value);
	lua_State* thread = CreateThread(l, -1);
	lua_xmove(l, thread, 1);

	int res;
	int error = lua_resume(thread, l, 0, &res);
	if (error == LUA_OK)
		((PJASS_DATA_SLOT)(esi + 80))->set(lua_toboolean(thread, 1), OPCODE_VARIABLE_BOOLEAN);
	else if (error == LUA_ERRRUN)
	{
		printf("[LUA] Lua error.\n");
		printf("%s\n", lua_tostring(l, -1));
	}

	return TRUE;
}