#include "LuaRegister.h"

#include "WarcraftFunctions.h"
#include "Variables.h"
#include "Warcraft.h"
#include "JassNatives.h"

#define lua_registerJassNative(L, n, f) (lua_pushstring(L, (n)), lua_pushcclosure(L, (f), 1), lua_setglobal(L, (n)))

LUA lua_jCall(lua_State* l) {
	LPCSTR name = lua_tostring(l, lua_upvalueindex(1));
	JASSNATIVE native = get_native(name);

	if (!native.is_valid()) {
		return 0;
	}

	{
		std::vector<JASS_TYPE> params = native.get_params();
		if ((int)params.size() > lua_gettop(l)) {
			return 0;
		}

		// if (native.is_sleep()) {
		// 	lua_yield(l, NULL);
		// }
	}

	std::vector<DWORD> temp_params;
	std::vector<DWORD> params;
	UINT i = 1;

	for (const auto& type : native.get_params()) {
		switch (type) {
		case TYPE_CODE:
			if (lua_isinteger(l, i)) {
				params.push_back((DWORD)lua_tointeger(l, i));
			}
			else if (lua_isfunction(l, i)) {
				params.push_back(to_Code(l, i));
			}

			break;
		case TYPE_BOOLEAN:
			params.push_back((DWORD)lua_toboolean(l, i));

			break;
		case TYPE_HANDLE:
			params.push_back((DWORD)lua_tointeger(l, i));

			break;
		case TYPE_INTEGER:
			if (lua_isinteger(l, i)) {
				params.push_back((DWORD)lua_tointeger(l, i));
			}
			else {
				params.push_back(to_ID(lua_tostring(l, i)));
			}

			break;
		case TYPE_REAL:
			temp_params.push_back(to_jReal((float)lua_tonumber(l, i)));
			params.push_back((DWORD) & (temp_params[temp_params.size() - 1]));

			break;
		case TYPE_STRING:
			params.push_back(to_jString(lua_tostring(l, i)));

			break;
		default:
			params.push_back(NULL);

			break;
		}

		i++;
	}

	DWORD result = native.call(params);

	switch (native.get_rettype()) {
	case TYPE_BOOLEAN:
		lua_pushboolean(l, result);

		break;

	case TYPE_CODE:
	case TYPE_HANDLE:
	case TYPE_INTEGER:
		lua_pushinteger(l, result);

		break;
	case TYPE_REAL:
		lua_pushnumber(l, from_jReal(result));

		break;
	case TYPE_STRING:
		lua_pushstring(l, from_jString(getJassMachine()->string_table->get(result)));

		break;
	}

	return native.get_rettype() != TYPE_NOTHING ? 1 : 0;
}

LUA lua_GetMouseWorldPos(lua_State* l) {
	PVECTOR3 mousePos = GetMouseWorldPos();

	lua_pushnumber(l, mousePos->_x);
	lua_pushnumber(l, mousePos->_y);
	lua_pushnumber(l, mousePos->_z);

	return 3;
}

LUA lua_GetMouseWorldX(lua_State* l) {
	lua_pushnumber(l, GetMouseWorldX());

	return 1;
}

LUA lua_GetMouseWorldY(lua_State* l) {
	lua_pushnumber(l, GetMouseWorldY());

	return 1;
}

LUA lua_GetMouseWorldZ(lua_State* l) {
	lua_pushnumber(l, GetMouseWorldZ());

	return 1;
}

LUA lua_GetObjectPos(lua_State* l) {
	PVECTOR3 objectPos = GetObjectPos(ConvertHandleToObject((UINT)lua_tointeger(l, 1)));

	lua_pushnumber(l, objectPos->_x);
	lua_pushnumber(l, objectPos->_y);
	lua_pushnumber(l, objectPos->_z);

	return 3;
}

LUA lua_GetObjectX(lua_State* l) {
	lua_pushnumber(l, GetObjectPos(ConvertHandleToObject((UINT)lua_tointeger(l, 1)))->_x);

	return 1;
}

LUA lua_GetObjectY(lua_State* l) {
	lua_pushnumber(l, GetObjectPos(ConvertHandleToObject((UINT)lua_tointeger(l, 1)))->_y);

	return 1;
}

LUA lua_GetObjectZ(lua_State* l) {
	lua_pushnumber(l, GetObjectPos(ConvertHandleToObject((UINT)lua_tointeger(l, 1)))->_z);

	return 1;
}

LUA lua_SetObjectPos(lua_State* l) {
	UINT_PTR object = ConvertHandleToObject((UINT)lua_tointeger(l, 1));

	switch (lua_gettop(l))
	{
	case 2:
		SetObjectX(object, (float)lua_tonumber(l, 2));

		break;
	case 3:
		SetObjectX(object, (float)lua_tonumber(l, 2));
		SetObjectY(object, (float)lua_tonumber(l, 3));

		break;
	case 4:
		SetObjectPos(object, VECTOR3((float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3), (float)lua_tonumber(l, 4)));

		break;
	}

	return 0;
}

LUA lua_SetObjectX(lua_State* l) {
	SetObjectX(ConvertHandleToObject((UINT)lua_tointeger(l, 1)), (float)lua_tonumber(l, 2));

	return 0;
}

LUA lua_SetObjectY(lua_State* l) {
	SetObjectY(ConvertHandleToObject((UINT)lua_tointeger(l, 1)), (float)lua_tonumber(l, 2));

	return 0;
}

LUA lua_SetObjectZ(lua_State* l) {
	SetObjectZ(ConvertHandleToObject((UINT)lua_tointeger(l, 1)), (float)lua_tonumber(l, 2));

	return 0;
}

LUA lua_ConvertHandleToObject(lua_State* l) {
	lua_pushinteger(l, ConvertHandleToObject((UINT)lua_tointeger(l, 1)));

	return 1;
}

//-------------------------------------------------------------

void lua_open_jassnatives(lua_State* l) {
	for (const auto& native : jassnatives) {
		lua_registerJassNative(l, native.first, lua_jCall);
	}
}

void lua_open_warcraftfunctions(lua_State* l) {
	lua_register(l, "GetMouseWorldPos", lua_GetMouseWorldPos);
	lua_register(l, "GetMouseWorldX", lua_GetMouseWorldX);
	lua_register(l, "GetMouseWorldY", lua_GetMouseWorldY);
	lua_register(l, "GetMouseWorldZ", lua_GetMouseWorldZ);

	lua_register(l, "GetObjectPos", lua_GetObjectPos);
	lua_register(l, "GetObjectX", lua_GetObjectX);
	lua_register(l, "GetObjectY", lua_GetObjectY);
	lua_register(l, "GetObjectZ", lua_GetObjectZ);

	lua_register(l, "SetObjectPos", lua_SetObjectPos);
	lua_register(l, "SetObjectX", lua_SetObjectX);
	lua_register(l, "SetObjectY", lua_SetObjectY);
	lua_register(l, "SetObjectZ", lua_SetObjectZ);

	lua_register(l, "ConvertHandleToObject", lua_ConvertHandleToObject);
}