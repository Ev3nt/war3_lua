#include "LuaMachine.h"

#include <fstream>
#include <Storm.h>
#pragma comment(lib, "storm.lib")

#include "Variables.h"
#include "LuaRegister.h"
#include "Warcraft.h"
#include "Mem.h"

lua_State* mainLuaState = NULL;
bool running = false;


//---------------------------------------------------------------------------------
// Utils

BOOL isInGameCatalog(LPCSTR fileName) {
	char filepath[MAX_PATH] = { 0 };
	GetFullPathName(fileName, sizeof(filepath), filepath, NULL);

	char path[MAX_PATH] = { 0 };
	GetModuleFileName(GetModuleHandle(NULL), path, sizeof(path));
	for (int i = strlen(path); path[i] != '\\'; path[i] = NULL, i--);

	return !_strnicmp(filepath, path, strlen(path)) ? TRUE : FALSE;
}

BOOL isAllowedExtension(LPCSTR fileName) {
	char* fileextension = (char*)fileName + strlen(fileName);

	for (; fileextension[0] != '.'; fileextension--);
	fileextension++;

	std::vector<LPCSTR> extensions = { "exe", "dll", "asi", "mix", "m3d", "mpq", "w3x", "w3m", "w3n" };
	for (const auto& extension : extensions) {
		if (!_strnicmp(fileextension, extension, strlen(extension))) {
			return FALSE;
		}
	}

	return TRUE;
}

//---------------------------------------------------------------------------------
// File stream only in catalog

// Open
luaL_Stream* newprefile(lua_State* L) {
	luaL_Stream* p = (luaL_Stream*)lua_newuserdatauv(L, sizeof(luaL_Stream), 0);
	p->closef = NULL;
	luaL_setmetatable(L, LUA_FILEHANDLE);
	return p;
}

int io_fclose(lua_State* L) {
	luaL_Stream* p = (luaL_Stream*)luaL_checkudata(L, 1, LUA_FILEHANDLE);
	int res = fclose(p->f);
	return luaL_fileresult(L, (res == 0), NULL);
}

luaL_Stream* newfile(lua_State* L) {
	luaL_Stream* p = newprefile(L);
	p->f = NULL;
	p->closef = &io_fclose;
	return p;
}

int l_checkmode(const char* mode) {
	return (*mode != '\0' && strchr("rwa", *(mode++)) != NULL && (*mode != '+' || ((void)(++mode), 1)) && (strspn(mode, "b") == strlen(mode)));
}

int io_open(lua_State* L) {
	const char* filename = luaL_checkstring(L, 1);
	const char* mode = luaL_optstring(L, 2, "r");

	if (!isInGameCatalog(filename) || !isAllowedExtension(filename)) {
		return luaL_fileresult(L, FALSE, filename);
	}

	luaL_Stream* p = newfile(L);
	const char* md = mode;
	luaL_argcheck(L, l_checkmode(md), 2, "invalid mode");
	fopen_s(&(p->f), filename, mode);
	return (p->f == NULL) ? luaL_fileresult(L, 0, filename) : 1;
}

// Remove
int os_remove(lua_State* L) {
	const char* filename = luaL_checkstring(L, 1);

	if (!isInGameCatalog(filename) || !isAllowedExtension(filename)) {
		return luaL_fileresult(L, FALSE, filename);
	}

	return luaL_fileresult(L, remove(filename) == 0, filename);
}

// Rename
int os_rename(lua_State* L) {
	const char* fromname = luaL_checkstring(L, 1);
	const char* toname = luaL_checkstring(L, 2);

	if (!isInGameCatalog(fromname) || !isAllowedExtension(fromname) || !isInGameCatalog(toname) || !isAllowedExtension(toname)) {
		return luaL_fileresult(L, FALSE, NULL);
	}

	return luaL_fileresult(L, rename(fromname, toname) == 0, NULL);
}

void lua_replaceFileStreamFunctions(lua_State* l) {
	lua_getglobal(l, "io");
	lua_pushcfunction(l, io_open);
	lua_setfield(l, -2, "open");

	lua_pop(l, 1);

	lua_getglobal(l, "os");
	lua_pushcfunction(l, os_remove);
	lua_setfield(l, -2, "remove");

	lua_pushcfunction(l, os_rename);
	lua_setfield(l, -2, "rename");

	lua_pop(l, 1);
}

//---------------------------------------------------------------------------------
// Disabled functions

void disable_functions(lua_State* l) {
	lua_getglobal(l, "os");

	std::vector<LPCSTR> functions = { "execute", "getenv", "setlocale", "tmpname" };

	for (const auto& function : functions) {
		lua_pushnil(l);
		lua_setfield(l, -2, function);
	}

	lua_pop(l, 1);

	lua_getglobal(l, "io");

	functions = { "stdin", "stdout", "stderr", "flush", "input", "lines", "output", "popen", "tmpfile", "type" };

	for (const auto& function : functions) {
		lua_pushnil(l);
		lua_setfield(l, -2, function);
	}

	lua_pop(l, 1);

	lua_pushnil(l);
	lua_setglobal(l, "dofile");

}

//---------------------------------------------------------------------------------
// Loader lua from mpq


// Lua
int checkload(lua_State* L, int stat, const char* filename) {
	if (stat) {
		lua_pushstring(L, filename);
		return 2;
	}
	else {
		return luaL_error(L, "error loading module '%s' from file '%s':\n\t%s", lua_tostring(L, 1), filename, lua_tostring(L, -1));
	}
}

int searcher_Lua(lua_State* l) {
	HANDLE map = *(HANDLE*)MakePtr(gameBase, _mapMPQ);

	std::string scriptName = luaL_checkstring(l, 1) + std::string(".lua");
	lua_pop(l, 1);

	char mapName[MAX_PATH] = { 0 };
	SFileGetArchiveName(map, mapName, sizeof(mapName));
	std::string scriptPath = mapName;

	for (size_t i = scriptPath.size(); i > 0; i--) {
		if (scriptPath[i] == '\\') {
			scriptPath = scriptPath.substr(i + 1);

			break;
		}
	}

	scriptPath = "(" + scriptPath + "):\\" + scriptName;

	HANDLE script;
	if (SFileOpenFileEx(map, scriptName.c_str(), NULL, &script)) {
		int lenght = SFileGetFileSize(script, NULL);
		char* buffer = new char[lenght + 1];
	
		ZeroMemory(buffer, lenght + 1);

		SFileReadFile(script, buffer, lenght, NULL, NULL);
		SFileCloseFile(script);

		int result = checkload(l, (luaL_loadbuffer(l, buffer, strlen(buffer), ("@"  + scriptPath).c_str()) == LUA_OK), scriptName.c_str());
		delete[] buffer;
	
		return result;
	}

	lua_pushstring(l, std::string("no file '" + scriptPath + "'").c_str());

	return 1;
}

void lua_replaceSearchers(lua_State* l) {
	std::vector<lua_CFunction> searchers;

	lua_getglobal(l, "package");
	lua_getfield(l, -1, "searchers");

	lua_rawgeti(l, -1, 1);
	searchers.push_back(lua_tocfunction(l, -1));
	lua_pop(l, 2);

	searchers.push_back(searcher_Lua);

	lua_newtable(l);

	for (size_t i = 0; i < searchers.size(); i++) {
		lua_pushvalue(l, -2);
		lua_pushcclosure(l, searchers[i], 1);
		lua_rawseti(l, -2, i + 1);
	}

	lua_setfield(l, -2, "searchers");

	lua_pop(l, 1);
	searchers.clear();
}

//---------------------------------------------------------------------------------

lua_State* getMainLuaState() {
	if (!mainLuaState) {
		lua_State* l = mainLuaState = luaL_newstate();

		luaL_openlibs(l);
		disable_functions(l);
		lua_open_jassnatives(l);
		lua_open_warcraftfunctions(l);
		lua_replaceSearchers(l);
		lua_replaceFileStreamFunctions(l);
	}

	return mainLuaState;
}

lua_State* createThread(lua_State* l, int index) {
	lua_pushvalue(l, index);
	getGlobalTable(l, "_LUA_THREADS", false);
	lua_pushvalue(l, -2);
	
	if (lua_rawget(l, -2) != LUA_TTHREAD) {
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

void clearScreen() {
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		return;
	}

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count)) {
		return;
	}

	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) {
		return;
	}

	SetConsoleCursorPosition(hStdOut, homeCoords);
}

void destroyMainLuaState()
{
	if (mainLuaState) {
		lua_close(mainLuaState);
		mainLuaState = NULL;
		running = false;
		triggers.clear();
		frameEventHashTable.clear();
	}

	clearScreen();
}

lua_State* getMainThread(lua_State* thread) {
	lua_rawgeti(thread, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
	lua_State* l = lua_tothread(thread, -1);
	lua_pop(thread, 1);

	return l;
}

BOOL getGlobalTable(lua_State* l, LPCSTR name, bool weak) {
	lua_getfield(l, LUA_REGISTRYINDEX, name);

	if (!lua_istable(l, -1)) {
		lua_pop(l, 1);
		lua_newtable(l);

		if (weak) {
			lua_newtable(l);
			lua_pushstring(l, "__mode");
			lua_pushstring(l, "kv");
			lua_rawset(l, -3);

			lua_setmetatable(l, -2);
		}

		lua_pushvalue(l, -1);
		lua_setfield(l, LUA_REGISTRYINDEX, name);

		return FALSE;
	}

	return TRUE;
}

int pushFunctionRef(lua_State* l, int index) {
	lua_pushvalue(l, index);
	getGlobalTable(l, "_LUA_FUNCTIONS_REF", false);

	int ref = (int)lua_rawlen(l, -1);
	lua_pushvalue(l, -2);
	lua_rawseti(l, -2, ++ref);

	lua_pop(l, 2);

	return ref;
}

void getFunctionByRef(lua_State* l, int ref) {
	getGlobalTable(l, "_LUA_FUNCTIONS_REF", false);
	lua_rawgeti(l, -1, ref);
	lua_remove(l, -2);
}

void lua_throwerr(lua_State* l) {
	running = false;

	LPCSTR error = lua_tostring(l, -1);
	printf("--------------------Lua Error--------------------\n%s\n-------------------------------------------------\n\n", error);
	MessageBox(FindWindow("Warcraft III", NULL), error, "Lua Error", MB_ICONHAND | MB_TOPMOST );
}

LUA stacktrace(lua_State* L)
{
	luaL_traceback(L, L, lua_tostring(L, -1), 0);

	return 1;
}

DWORD startLua() {
	destroyMainLuaState();

	lua_State* l = getMainLuaState();

	HANDLE war3luaScript;
	
	if (SFileOpenFileEx(*(HANDLE*)MakePtr(gameBase, _mapMPQ), "war3map.lua", NULL, &war3luaScript)) {
		SFileCloseFile(war3luaScript);

		running = true;

		lua_pushcfunction(l, stacktrace);
		lua_getglobal(l, "require");
		lua_pushstring(l, "war3map");
		if (lua_pcall(l, 1, LUA_MULTRET, -3) != LUA_OK) {
			lua_throwerr(l);
		}

		lua_pop(l, 1);
	}

	return 0;
}

BOOL __stdcall startLuaThread(DWORD esi, DWORD edi) {
	if (!running) {
		return FALSE;
	}

	PJASS_STACK stack = (PJASS_STACK) * (DWORD*)(esi + 0x2868);

	lua_State* l = (lua_State*)stack->pop()->value;
	getFunctionByRef(l, stack->pop()->value);
	lua_State* thread = createThread(l, -1);
	lua_xmove(l, thread, 1);

	int res;
	switch (lua_resume(thread, l, 0, &res)) {
	case LUA_OK:
		((PJASS_DATA_SLOT)(esi + 80))->set(lua_toboolean(thread, 1), OPCODE_VARIABLE_BOOLEAN);

		break;
	case LUA_ERRRUN:
		lua_throwerr(thread);

		break;
	}

	return TRUE;
}