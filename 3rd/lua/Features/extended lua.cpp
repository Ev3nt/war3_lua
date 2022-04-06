#include "extended lua.h"

LUA_API void lua_push(lua_State* L, UINT value, int type) {
	lua_lock(L);
	setvalue(s2v(L->top), value, type);
	api_incr_top(L);
	lua_unlock(L);
}

//LUA_API lua_Integer lua_to(lua_State* L, int idx, int type) {
//	lua_Integer res = 0;
//	const TValue* o = index2value(L, idx);
//	int isnum = tointeger(o, &res);
//	if (pisnum)
//		*pisnum = isnum;
//	return res;
//}