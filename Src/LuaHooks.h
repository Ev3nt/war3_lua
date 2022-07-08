#pragma once

namespace LuaHooks {
	void lua_replaceSearchers(lua_State* l);
	void lua_disableFunctions(lua_State* l);
	void lua_replaceFileStreamFunctions(lua_State* l);
	void lua_replaceGlobals(lua_State* l);
}