#include "LuaFunctions.h"
#include "JassNatives.h"
#include "GameUI.h"
#include "Warcraft.h"

#define lua_registerJassNative(L, n, f) (lua_pushstring(L, (n)), lua_pushcclosure(L, (f), 1), lua_setglobal(L, (n)))
#define lua_registerex(L, n, c, f) (lua_pushstring(L, (n)), lua_pushinteger(L, (c)), lua_pushcclosure(L, (f), 2), lua_setglobal(L, (n)))
#define lua_setint(L, n, v) (lua_pushinteger(L, v), lua_setglobal(L, n))

BOOL checkParams(lua_State* l) {
	LPCSTR name = lua_tostring(l, lua_upvalueindex(1));
	int size = (int)lua_tointeger(l, lua_upvalueindex(2));

	if (size > lua_gettop(l)) {
		return luaL_error(l, "function '%s' must have %d %s", name, size, size > 1 ? "arguments" : "argument");
	}

	return FALSE;
}

//--------------------------------------------------------
// JassNatives

int lua_callNative(lua_State* l) {
	LPCSTR name = lua_tostring(l, lua_upvalueindex(1));
	JASSNATIVE native = get_native(name);

	if (!native.is_valid()) {
		return 0;
	}

	int size = native.get_params().size();
	if (size > lua_gettop(l)) {
		return luaL_error(l, "function '%s' must have %d %s", name, size, size > 1 ? "arguments" : "argument");
	}

	size = lua_gettop(l);

	float* float_params = new float[size];
	DWORD* params = new DWORD[size];
	ZeroMemory(float_params, size);
	ZeroMemory(params, size);
	UINT i = 1;

	for (const auto& type : native.get_params()) {
		switch (type) {
		case TYPE_CODE:
			if (lua_isinteger(l, i)) {
				params[i - 1] = (DWORD)lua_tointeger(l, i);
			}
			else if (lua_isfunction(l, i)) {
				params[i - 1] = to_code(l, i);
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
			float_params[i - 1] = (float)lua_tonumber(l, i);
			params[i - 1] = (DWORD)&(float_params[i - 1]);

			break;
		}
		case TYPE_STRING:
			params[i - 1] = to_string(lua_tostring(l, i));

			break;
		default:
			params[i - 1] = NULL;

			break;
		}

		i++;
	}

	BOOL result = native.call(params, size);
	delete[] float_params;
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
		lua_pushnumber(l, from_real(result));

		break;
	case TYPE_STRING:
		lua_pushstring(l, from_string(getJassMachine()->string_table->get(result)));

		break;
	}

	return native.get_rettype() != TYPE_NOTHING ? 1 : 0;
}

//--------------------------------------------------------

void lua_openJassNatives(lua_State* l) {
	for (const auto& native : jassnatives) {
		lua_registerJassNative(l, native.first, lua_callNative);
	}
}

//--------------------------------------------------------
// MouseAPI

//--------------------------------------------------------

//--------------------------------------------------------
// FrameAPI

int lua_GetOriginFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetOriginFrame((EOriginFrame)lua_tointeger(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

int lua_LoadTOCFile(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, LoadTOCFile(lua_tostring(l, 1)));

	return 1;
}

int lua_GetFrameByName(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFrameByName(lua_tostring(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFrameParent(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFrameParent((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_GetFrameChildrenCount(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFrameChildrenCount((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_GetFrameChild(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFrameChild((UINT)lua_tointeger(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

int lua_TriggerRegisterFrameEvent(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	TriggerRegisterFrameEvent((UINT)lua_tointeger(l, 1), (UINT)lua_tointeger(l, 2), (EFrameEvent)lua_tointeger(l, 3));

	return 0;
}

int lua_CreateFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, CreateFrame(lua_tostring(l, 1), (UINT)lua_tointeger(l, 2), (EFramePoint)lua_tointeger(l, 3), (EFramePoint)lua_tointeger(l, 4) /*(UINT)lua_tointeger(l, 5)*/));

	return 1;
}

int lua_SetFrameText(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameText((UINT)lua_tointeger(l, 1), lua_tostring(l, 2));

	return 0;
}

int lua_GetFrameText(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushstring(l, GetFrameText((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_SetFrameTextColor(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameTextColor((UINT)lua_tointeger(l, 1), (BYTE)lua_tointeger(l, 2), (BYTE)lua_tointeger(l, 3), (BYTE)lua_tointeger(l, 4), (BYTE)lua_tointeger(l, 5));

	return 0;
}

int lua_GetFrameTextHeight(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameTextHeight((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_SetFrameWidth(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameWidth((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameHeight(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameHeight((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameSize(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameSize((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3));

	return 0;
}

int lua_SetFrameScale(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameScale((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameAbsolutePoint(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameAbsolutePoint((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2), (float)lua_tonumber(l, 3), (float)lua_tonumber(l, 4));

	return 0;
}

int lua_SetFramePoint(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFramePoint((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2), (UINT)lua_tointeger(l, 3), (EFramePoint)lua_tointeger(l, 4), (float)lua_tonumber(l, 5), (float)lua_tonumber(l, 6));

	return 0;
}

int lua_GetFrameWidth(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameWidth((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_GetFrameHeight(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameHeight((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_GetFramePointParent(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFramePointParent((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFramePointRelativePoint(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFramePointRelativePoint((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFramePointX(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFramePointX((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFramePointY(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFramePointY((UINT)lua_tointeger(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetTriggerFrame(lua_State* l) {
	lua_pushinteger(l, GetTriggerFrame());

	return 1;
}

int lua_GetFrameValue(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameValue((UINT)lua_tointeger(l, 1)));

	return 1;
}

int lua_GetTriggerFrameValue(lua_State* l) {
	lua_pushnumber(l, GetTriggerFrameValue());

	return 1;
}

int lua_SetFrameValue(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameValue((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameMinMaxValue(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameMinMaxValue((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3));

	return 0;
}

int lua_SetFrameStepSize(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameStepSize((UINT)lua_tointeger(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameTexture(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameTexture((UINT)lua_tointeger(l, 1), lua_tostring(l, 2), lua_toboolean(l, 3));

	return 0;
}

int lua_SetFrameEnable(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameEnable((UINT)lua_tointeger(l, 1), lua_toboolean(l, 2));

	return 0;
}

int lua_ClickFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	ClickFrame((UINT)lua_tointeger(l, 1));

	return 0;
}

int lua_SetFrameModel(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameModel((UINT)lua_tointeger(l, 1), lua_tostring(l, 2), (UINT)lua_tointeger(l, 3), (BOOL)lua_toboolean(l, 4));

	return 0;
}

int lua_DestroyFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	DestroyFrame((UINT)lua_tointeger(l, 1));

	return 0;
}

int lua_SetFrameVisible(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameVisible((UINT)lua_tointeger(l, 1), (BOOL)lua_toboolean(l, 2));

	return 0;
}

int lua_SetGameUIVisible(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetGameUIVisible((BOOL)lua_toboolean(l, 1));

	return 0;
}

int lua_SetFrameCheck(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameCheck((UINT)lua_tointeger(l, 1), (BOOL)lua_toboolean(l, 2));

	return 0;
}

//--------------------------------------------------------

void lua_openFrameAPI(lua_State* l) {
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

	lua_setint(l, "FRAMEPOINT_TOPLEFT", FRAMEPOINT_TOPLEFT);
	lua_setint(l, "FRAMEPOINT_TOP", FRAMEPOINT_TOP);
	lua_setint(l, "FRAMEPOINT_TOPRIGHT", FRAMEPOINT_TOPRIGHT);
	lua_setint(l, "FRAMEPOINT_LEFT", FRAMEPOINT_LEFT);
	lua_setint(l, "FRAMEPOINT_CENTER", FRAMEPOINT_CENTER);
	lua_setint(l, "FRAMEPOINT_RIGHT", FRAMEPOINT_RIGHT);
	lua_setint(l, "FRAMEPOINT_BOTTOMLEFT", FRAMEPOINT_BOTTOMLEFT);
	lua_setint(l, "FRAMEPOINT_BOTTOM", FRAMEPOINT_BOTTOM);
	lua_setint(l, "FRAMEPOINT_BOTTOMRIGHT", FRAMEPOINT_BOTTOMRIGHT);

	lua_setint(l, "FRAMEEVENT_CONTROL_CLICK", FRAMEEVENT_CONTROL_CLICK);
	lua_setint(l, "FRAMEEVENT_MOUSE_ENTER", FRAMEEVENT_MOUSE_ENTER);
	lua_setint(l, "FRAMEEVENT_MOUSE_LEAVE", FRAMEEVENT_MOUSE_LEAVE);
	lua_setint(l, "FRAMEEVENT_MOUSE_UP", FRAMEEVENT_MOUSE_UP);
	lua_setint(l, "FRAMEEVENT_MOUSE_DOWN", FRAMEEVENT_MOUSE_DOWN);
	lua_setint(l, "FRAMEEVENT_MOUSE_WHEEL", FRAMEEVENT_MOUSE_WHEEL);
	lua_setint(l, "FRAMEEVENT_CHECKBOX_CHECKED", FRAMEEVENT_CHECKBOX_CHECKED);
	lua_setint(l, "FRAMEEVENT_CHECKBOX_UNCHECKED", FRAMEEVENT_CHECKBOX_UNCHECKED);
	lua_setint(l, "FRAMEEVENT_EDITBOX_TEXT_CHANGED", FRAMEEVENT_EDITBOX_TEXT_CHANGED);
	lua_setint(l, "FRAMEEVENT_POPUPMENU_ITEM_CHANGED", FRAMEEVENT_POPUPMENU_ITEM_CHANGED);
	lua_setint(l, "FRAMEEVENT_MOUSE_DOUBLECLICK", FRAMEEVENT_MOUSE_DOUBLECLICK);
	lua_setint(l, "FRAMEEVENT_SPRITE_ANIM_UPDATE", FRAMEEVENT_SPRITE_ANIM_UPDATE);
	lua_setint(l, "FRAMEEVENT_SLIDER_VALUE_CHANGED", FRAMEEVENT_SLIDER_VALUE_CHANGED);
	lua_setint(l, "FRAMEEVENT_DIALOG_CANCEL", FRAMEEVENT_DIALOG_CANCEL);
	lua_setint(l, "FRAMEEVENT_DIALOG_ACCEPT", FRAMEEVENT_DIALOG_ACCEPT);
	lua_setint(l, "FRAMEEVENT_EDITBOX_ENTER", FRAMEEVENT_EDITBOX_ENTER);

	lua_registerex(l, "GetOriginFrame", 2, lua_GetOriginFrame);
	lua_registerex(l, "LoadTOCFile", 1, lua_LoadTOCFile);
	lua_registerex(l, "GetFrameByName", 2, lua_GetFrameByName);
	lua_registerex(l, "GetFrameParent", 1, lua_GetFrameParent);
	lua_registerex(l, "GetFrameChildrenCount", 1, lua_GetFrameChildrenCount);
	lua_registerex(l, "GetFrameChild", 2, lua_GetFrameChild);
	lua_registerex(l, "TriggerRegisterFrameEvent", 3, lua_TriggerRegisterFrameEvent);
	lua_registerex(l, "CreateFrame", 4, lua_CreateFrame);
	lua_registerex(l, "SetFrameText", 2, lua_SetFrameText);
	lua_registerex(l, "GetFrameText", 1, lua_GetFrameText);
	lua_registerex(l, "SetFrameTextColor", 5, lua_SetFrameTextColor);
	lua_registerex(l, "GetFrameTextHeight", 1, lua_GetFrameTextHeight);
	lua_registerex(l, "SetFrameWidth", 2, lua_SetFrameWidth);
	lua_registerex(l, "SetFrameHeight", 2, lua_SetFrameHeight);
	lua_registerex(l, "SetFrameSize", 3, lua_SetFrameSize);
	lua_registerex(l, "SetFrameScale", 2, lua_SetFrameScale);
	lua_registerex(l, "SetFrameAbsolutePoint", 4, lua_SetFrameAbsolutePoint);
	lua_registerex(l, "SetFramePoint", 6, lua_SetFramePoint);
	lua_registerex(l, "GetFrameWidth", 1, lua_GetFrameWidth);
	lua_registerex(l, "GetFrameHeight", 1, lua_GetFrameHeight);
	lua_registerex(l, "GetFramePointParent", 2, lua_GetFramePointParent);
	lua_registerex(l, "GetFramePointRelativePoint", 2, lua_GetFramePointRelativePoint);
	lua_registerex(l, "GetFramePointX", 2, lua_GetFramePointX);
	lua_registerex(l, "GetFramePointY", 2, lua_GetFramePointY);
	lua_registerex(l, "GetTriggerFrame", 0, lua_GetTriggerFrame);
	lua_registerex(l, "GetFrameValue", 1, lua_GetFrameValue);
	lua_registerex(l, "GetTriggerFrameValue", 0, lua_GetTriggerFrameValue);
	lua_registerex(l, "SetFrameValue", 2, lua_SetFrameValue);
	lua_registerex(l, "SetFrameMinMaxValue", 3, lua_SetFrameMinMaxValue);
	lua_registerex(l, "SetFrameStepSize", 2, lua_SetFrameStepSize);
	lua_registerex(l, "SetFrameTexture", 3, lua_SetFrameTexture);
	lua_registerex(l, "SetFrameEnable", 2, lua_SetFrameEnable);
	lua_registerex(l, "ClickFrame", 1, lua_ClickFrame);
	lua_registerex(l, "SetFrameModel", 4, lua_SetFrameModel);
	lua_registerex(l, "DestroyFrame", 1, lua_DestroyFrame);
	lua_registerex(l, "SetFrameVisible", 2, lua_SetFrameVisible);
	lua_registerex(l, "SetGameUIVisible", 1, lua_SetGameUIVisible);
	lua_registerex(l, "SetFrameCheck", 2, lua_SetFrameCheck);
}