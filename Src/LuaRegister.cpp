#include "LuaRegister.h"

#include "WarcraftFunctions.h"
#include "Variables.h"
#include "Warcraft.h"
#include "JassNatives.h"

#define lua_registerJassNative(L, n, f) (lua_pushstring(L, (n)), lua_pushcclosure(L, (f), 1), lua_setglobal(L, (n)))
#define lua_setint(L, n, v) (lua_pushinteger(L, v), lua_setglobal(L, n))

LUA lua_jCall(lua_State* l) {
	LPCSTR name = lua_tostring(l, lua_upvalueindex(1));
	JASSNATIVE native = get_native(name);
	
	if (!native.is_valid()) {
		return 0;
	}

	{
		std::vector<JASS_TYPE> params = native.get_params();
		int size = params.size();
		if (size > lua_gettop(l)) {
			return luaL_error(l, "function '%s' must have %d %s", name, size, size > 1 ? "arguments" : "argument");
		}
	}

	int size = lua_gettop(l);
	float* temp_params = new float[size];
	DWORD* params = new DWORD[size];
	ZeroMemory(temp_params, size);
	ZeroMemory(params, size);
	UINT i = 1;

	for (const auto& type : native.get_params()) {
		switch (type) {
		case TYPE_CODE:
			if (lua_isinteger(l, i)) {
				params[i - 1] = (DWORD)lua_tointeger(l, i);
			}
			else if (lua_isfunction(l, i)) {
				params[i - 1] = to_Code(l, i);
			}

			break;
		case TYPE_BOOLEAN:
			params[i - 1] = (DWORD)lua_toboolean(l, i);

			break;
		case TYPE_HANDLE:
			params[i - 1] = (DWORD)lua_tointeger(l, i);

			break;
		case TYPE_INTEGER:
			if (lua_isinteger(l, i)) {
				params[i - 1] = (DWORD)lua_tointeger(l, i);
			}
			else {
				params[i - 1] = to_ID(lua_tostring(l, i));
			}

			break;
		case TYPE_REAL: {
			temp_params[i - 1] = (float)lua_tonumber(l, i);
			params[i - 1] = (DWORD)&(temp_params[i - 1]);

			break;
		}
		case TYPE_STRING:
			params[i - 1] = to_jString(lua_tostring(l, i));

			break;
		default:
			params[i - 1] = NULL;

			break;
		}

		i++;
	}

	DWORD result = native.call(params, size);
	delete[] temp_params;
	delete[] params;

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

//-------------------------------------------------------------

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

LUA lua_GetOriginFrame(lua_State* l) {
	lua_pushinteger(l, GetOriginFrame((EOriginFrame)lua_tointeger(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_LoadTOCFile(lua_State* l) {
	lua_pushinteger(l, LoadTOCFile(lua_tostring(l, 1)));

	return 1;
}

LUA lua_GetFrameByName(lua_State* l) {
	lua_pushinteger(l, GetFrameByName(lua_tostring(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_CreateFrame(lua_State* l) {
	lua_pushinteger(l, CreateFrame(lua_tostring(l, 1), (UINT)lua_tointeger(l, 2), (EFramePoint)lua_tointeger(l, 3), (EFramePoint)lua_tointeger(l, 4), (UINT)lua_tointeger(l, 5)));

	return 1;
}

LUA lua_SetFrameText(lua_State* l) {
	SetFrameText((UINT)lua_tointeger(l, 1), lua_tostring(l, 2));

	return 0;
}

LUA lua_SetFrameTextColor(lua_State* l) {
	SetFrameTextColor((UINT)lua_tointeger(l, 1), (BYTE)lua_tointeger(l, 2), (BYTE)lua_tointeger(l, 3), (BYTE)lua_tointeger(l, 4), (BYTE)lua_tointeger(l, 5));

	return 0;
}

LUA lua_GetFrameTextHeight(lua_State* l) {
	lua_pushnumber(l, GetFrameTextHeight((UINT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_SetFrameWidth(lua_State* l) {
	SetFrameWidth((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

LUA lua_SetFrameHeight(lua_State* l) {
	SetFrameHeight((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

LUA lua_SetFrameSize(lua_State* l) {
	SetFrameSize((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3));

	return 0;
}

LUA lua_SetFrameScale(lua_State* l) {
	SetFrameScale((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

LUA lua_SetFrameAbsolutePoint(lua_State* l) {
	SetFrameAbsolutePoint((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2), (float)lua_tonumber(l, 3), (float)lua_tonumber(l, 4));

	return 0;
}

LUA lua_SetFramePoint(lua_State* l) {
	SetFramePoint((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2), (UINT)lua_tointeger(l, 3), (EFramePoint)lua_tointeger(l, 4), (float)lua_tonumber(l, 5), (float)lua_tonumber(l, 6));

	return 0;
}

LUA lua_GetFrameWidth(lua_State* l) {
	lua_pushnumber(l, GetFrameWidth((UINT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetFrameHeight(lua_State* l) {
	lua_pushnumber(l, GetFrameHeight((UINT)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_GetFramePointParent(lua_State* l) {
	lua_pushinteger(l, GetFramePointParent((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetFramePointRelativePoint(lua_State* l) {
	lua_pushinteger(l, GetFramePointRelativePoint((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetFramePointX(lua_State* l) {
	lua_pushnumber(l, GetFramePointX((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_GetFramePointY(lua_State* l) {
	lua_pushnumber(l, GetFramePointY((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

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

	lua_setint(l, "ORIGIN_FRAME_GAME_UI", ORIGIN_FRAME_GAME_UI);
	lua_setint(l, "ORIGIN_FRAME_WORLD_FRAME", ORIGIN_FRAME_WORLD_FRAME);
	lua_setint(l, "ORIGIN_FRAME_HERO_BAR", ORIGIN_FRAME_HERO_BAR);
	lua_setint(l, "ORIGIN_FRAME_HERO_BUTTON", ORIGIN_FRAME_HERO_BUTTON);
	lua_setint(l, "ORIGIN_FRAME_HERO_HP_BAR", ORIGIN_FRAME_HERO_HP_BAR);
	lua_setint(l, "ORIGIN_FRAME_HERO_MANA_BAR", ORIGIN_FRAME_HERO_MANA_BAR);
	lua_setint(l, "ORIGIN_FRAME_HERO_BUTTON_INDICATOR", ORIGIN_FRAME_HERO_BUTTON_INDICATOR);
	lua_setint(l, "ORIGIN_FRAME_ITEM_BUTTON", ORIGIN_FRAME_ITEM_BUTTON);
	lua_setint(l, "ORIGIN_FRAME_COMMAND_BUTTON", ORIGIN_FRAME_COMMAND_BUTTON);
	lua_setint(l, "ORIGIN_FRAME_SYSTEM_BUTTON", ORIGIN_FRAME_SYSTEM_BUTTON);
	lua_setint(l, "ORIGIN_FRAME_PORTRAIT", ORIGIN_FRAME_PORTRAIT);
	lua_setint(l, "ORIGIN_FRAME_MINIMAP", ORIGIN_FRAME_MINIMAP);
	lua_setint(l, "ORIGIN_FRAME_MINIMAP_BUTTON", ORIGIN_FRAME_MINIMAP_BUTTON);
	lua_setint(l, "ORIGIN_FRAME_TOOLTIP", ORIGIN_FRAME_TOOLTIP);
	lua_setint(l, "ORIGIN_FRAME_UBERTOOLTIP", ORIGIN_FRAME_UBERTOOLTIP);
	lua_setint(l, "ORIGIN_FRAME_CHAT_MSG", ORIGIN_FRAME_CHAT_MSG);
	lua_setint(l, "ORIGIN_FRAME_UNIT_MSG", ORIGIN_FRAME_UNIT_MSG);
	lua_setint(l, "ORIGIN_FRAME_TOP_MSG", ORIGIN_FRAME_TOP_MSG);

	lua_register(l, "GetOriginFrame", lua_GetOriginFrame);
	lua_register(l, "LoadTOCFile", lua_LoadTOCFile);
	lua_register(l, "GetFrameByName", lua_GetFrameByName);
	lua_register(l, "CreateFrame", lua_CreateFrame);
	lua_register(l, "SetFrameText", lua_SetFrameText);
	lua_register(l, "SetFrameTextColor", lua_SetFrameTextColor);
	lua_register(l, "GetFrameTextHeight", lua_GetFrameTextHeight);
	lua_register(l, "SetFrameWidth", lua_SetFrameWidth);
	lua_register(l, "SetFrameHeight", lua_SetFrameHeight);
	lua_register(l, "SetFrameSize", lua_SetFrameSize);
	lua_register(l, "SetFrameScale", lua_SetFrameScale);
	lua_register(l, "SetFrameAbsolutePoint", lua_SetFrameAbsolutePoint);
	lua_register(l, "SetFramePoint", lua_SetFramePoint);
	lua_register(l, "GetFrameWidth", lua_GetFrameWidth);
	lua_register(l, "GetFrameHeight", lua_GetFrameHeight);
	lua_register(l, "GetFramePointParent", lua_GetFramePointParent);
	lua_register(l, "GetFramePointRelativePoint", lua_GetFramePointRelativePoint);
	lua_register(l, "GetFramePointX", lua_GetFramePointX);
	lua_register(l, "GetFramePointY", lua_GetFramePointY);
}