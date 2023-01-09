#include "pch.h"
#include "LuaHooks.h"
#include "EasyStormLib/EasyStormLib.h"
#include "Warcraft.h"
#include "Offsets.h"

namespace LuaHooks {
	//---------------------------------------------------------------------------------
	// Loader lua from mpq

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
		Storm::Archive map;
		std::string scriptName = luaL_checkstring(l, 1);

		size_t it;
		while ((it = scriptName.find('.')) != std::string::npos) {
			scriptName.replace(it, 1, "\\");
		}

		if (scriptName == "war3map") {
			map.Connect(*(HANDLE*)pOffsets[(UINT)Offset::LastPlayedMap]);
		}

		scriptName += std::string(".lua");
		lua_pop(l, 1);

		std::string mapPath = map.GetArchiveName(scriptName);
		if (mapPath.empty()) {
			map.Connect(*(HANDLE*)pOffsets[(UINT)Offset::LastPlayedMap]);
			mapPath = map.GetArchiveName();
			map.Close();
		}

		std::string scriptPath = "(" + mapPath + "):\\" + scriptName;

		std::string script = map[scriptName];
		if (!script.empty()) {
			return checkload(l, (luaL_loadbuffer(l, script.data(), script.size(), ("@" + scriptPath).data()) == LUA_OK), scriptName.data());
		}

		lua_pushstring(l, ("no file '" + scriptPath + "'").data());

		return 1;
	}

	int dofilecont(lua_State* l, int d1, lua_KContext d2) {
		return lua_gettop(l) - 1;
	}

	int luaL_loadbufferasfile(lua_State* l, LPCSTR buffer, size_t size, std::string name, LPCSTR mode = NULL) {
		int status = luaL_loadbufferx(l, buffer, size, ("@" + name).data(), mode);

		!size ? lua_pop(l, 1), lua_pushfstring(l, "cannot open %s: No such file or directory", name.data()) : NULL; // strerror(2)

		return size ? status : LUA_ERRFILE;
	}

	int lua_dofile(lua_State* l) {
		std::string scriptName = luaL_optstring(l, 1, NULL);
		lua_settop(l, 1);

		Storm::Archive map;
		std::string mapPath = map.GetArchiveName(scriptName);
		if (mapPath.empty()) {
			map.Connect(*(HANDLE*)pOffsets[(UINT)Offset::LastPlayedMap]);
			mapPath = map.GetArchiveName();
			map.Close();
		}

		std::string script = map[scriptName];
		if (luaL_loadbufferasfile(l, script.data(), script.size(), ("(" + mapPath + "):\\" + scriptName)) != LUA_OK) {
			if (developerMode) {
				lua_pop(l, 1);

				if (luaL_loadfile(l, scriptName.data()) != LUA_OK) {
					return lua_error(l);
				}
			}
			else {
				return lua_error(l);
			}
		}

		lua_callk(l, 0, LUA_MULTRET, 0, dofilecont);

		return dofilecont(l, 0, 0);
	}

	int load_aux(lua_State* l, int status, int envidx) {
		if (status == LUA_OK) {
			if (envidx) {
				lua_pushvalue(l, envidx);

				if (!lua_setupvalue(l, -2, 1)) {
					lua_pop(l, 1);
				}
			}

			return 1;
		}
		else {
			luaL_pushfail(l);
			lua_insert(l, -2);

			return 2;
		}
	}

	int lua_loadfile(lua_State* l) {
		std::string scriptName = luaL_optstring(l, 1, NULL);
		LPCSTR mode = luaL_optstring(l, 2, NULL);
		int env = (!lua_isnone(l, 3) ? 3 : 0);

		Storm::Archive map;
		std::string mapPath = map.GetArchiveName(scriptName);
		if (mapPath.empty()) {
			map.Connect(*(HANDLE*)pOffsets[(UINT)Offset::LastPlayedMap]);
			mapPath = map.GetArchiveName();
			map.Close();
		}

		std::string script = map[scriptName];
		int status = luaL_loadbufferasfile(l, script.data(), script.size(), ("(" + mapPath + "):\\" + scriptName));
		status != LUA_OK && developerMode ? lua_pop(l, 1), status = luaL_loadfilex(l, scriptName.data(), mode) : NULL;

		return load_aux(l, status, env);
	}

	//--------------------------------------------------------------

	void lua_replaceSearchers(lua_State* l) {
		std::vector<lua_CFunction> searchers;

		lua_getglobal(l, "package");
		lua_getfield(l, -1, "searchers");

		if (developerMode) {
			for (int i = 1; lua_rawgeti(l, -1, i); i++) {
				searchers.push_back(lua_tocfunction(l, -1));
				lua_pop(l, 1);
			}
			lua_pop(l, 2);

			searchers.insert(searchers.begin() + 1, searcher_Lua);
		}
		else {
			lua_rawgeti(l, -1, 1);
			searchers.push_back(lua_tocfunction(l, -1));
			lua_pop(l, 2);

			searchers.push_back(searcher_Lua);
		}

		lua_newtable(l);

		for (size_t i = 0; i < searchers.size(); i++) {
			lua_pushvalue(l, -2);
			lua_pushcclosure(l, searchers[i], 1);
			lua_rawseti(l, -2, i + 1);
		}

		lua_setfield(l, -2, "searchers");

		lua_pop(l, 1);
		searchers.clear();

		lua_register(l, "dofile", lua_dofile);
		lua_register(l, "loadfile", lua_loadfile);
	}

	// -------------------------------------------------------------------------------- -
	// Disabled functions

	void lua_disableFunctions(lua_State* l) {
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
		lua_setglobal(l, "debug");
	}

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

		if (!isInGameCatalog(filename) /*|| !isAllowedExtension(filename)*/) {
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

		if (!isInGameCatalog(filename) /*|| !isAllowedExtension(filename)*/) {
			return luaL_fileresult(L, FALSE, filename);
		}

		return luaL_fileresult(L, remove(filename) == 0, filename);
	}

	// Rename
	int os_rename(lua_State* L) {
		const char* fromname = luaL_checkstring(L, 1);
		const char* toname = luaL_checkstring(L, 2);

		if (!isInGameCatalog(fromname) /*|| !isAllowedExtension(fromname)*/ || !isInGameCatalog(toname) /*|| !isAllowedExtension(toname)*/) {
			return luaL_fileresult(L, FALSE, NULL);
		}

		return luaL_fileresult(L, rename(fromname, toname) == 0, NULL);
	}

	//---------------------------------------------------------------------------------

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
	// print

	int lua_printc(lua_State* L) {
		int n = lua_gettop(L);
		int i;

		for (i = 1; i <= n; i++) {
			LPCSTR s = luaL_tolstring(L, i, NULL);
			lua_pop(L, 1);

			if (i > 1) {
				printf("\t");
			}

			Utils::printf(s);
		}

		printf("\n");

		return 0;
	}

	int lua_print(lua_State* L) {
		int n = lua_gettop(L);
		int i;

		std::string string = "";

		for (i = 1; i <= n; i++) {
			if (i > 1) {
				string += "\t";
			}

			string += luaL_tolstring(L, i, NULL);
			lua_pop(L, 1);
		}

		Warcraft::PrintChat(string.data(), 60.f);

		return 0;
	}

	int luaB_getmetatable(lua_State* l) {
		luaL_checkany(l, 1);
		if (!lua_getmetatable(l, 1)) {
			lua_pushnil(l);

			return 1;
		}

		/*if (luaL_getmetafield(l, 1, "__metatable") == LUA_TSTRING) {
			if (luaL_testudata(l, 1, lua_tostring(l, 3))) {
				lua_pop(l, 2);
				lua_pushnil(l);
			}
		}*/

		if (luaL_getmetafield(l, 1, "__metatable") == LUA_TBOOLEAN) {
			if (lua_toboolean(l, -1) == FALSE) {
				lua_pop(l, 1);
				lua_pushnil(l);
			}
		}

		return 1;
	}

	int luaB_type(lua_State* l) {
		int t = lua_type(l, 1);
		luaL_argcheck(l, t != LUA_TNONE, 1, "value expected");

		if (t == LUA_TUSERDATA && luaL_getmetafield(l, 1, "__metatable") == LUA_TBOOLEAN) {
				lua_pop(l, 1);

				luaL_getmetafield(l, 1, "__name");
		}
		else {
			lua_pushstring(l, lua_typename(l, t));
		}

		return 1;
	}

	//---------------------------------------------------------------------------------

	void lua_replaceGlobals(lua_State* l) {
		lua_pushcfunction(l, lua_printc);
		lua_setglobal(l, "printc");

		lua_pushcfunction(l, lua_print);
		lua_setglobal(l, "print");

		lua_pushcfunction(l, luaB_getmetatable);
		lua_setglobal(l, "getmetatable");

		lua_pushcfunction(l, luaB_type);
		lua_setglobal(l, "type");
	}
}