#include "LuaFunctions.h"
#include "JassNatives.h"
#include "GameUI.h"
#include "MemHack.h"
#include "Warcraft.h"
#include "Utils.h"

#define lua_registerJassNative(L, n, f) (lua_pushstring(L, (n)), lua_pushcclosure(L, (f), 1), lua_setglobal(L, (n)))
#define lua_registerex(L, n, c, f) (lua_pushstring(L, (n)), lua_pushinteger(L, (c)), lua_pushcclosure(L, (f), 2), lua_setglobal(L, (n)))
#define lua_setint(L, n, v) (lua_pushinteger(L, v), lua_setglobal(L, n))

BOOL checkParams(lua_State* l) {
	LPCSTR name = lua_tostring(l, lua_upvalueindex(1));
	int size = (int)lua_tointeger(l, lua_upvalueindex(2));

	if (size > lua_gettop(l)) {
		return luaL_error(l, "function '%s' must have %d %s", name, size, size > 1 ? "arguments" : "argument");
	}

	for (int i = 1; i <= size; i++) {
		if (lua_isnil(l, i)) {
			return luaL_error(l, "Argument number %d of function '%s' mustn't be equal to nil", i, name);
		}
	}

	return FALSE;
}

//--------------------------------------------------------
// JassNatives

int lua_callNative(lua_State* l) {
	std::string name = lua_tostring(l, lua_upvalueindex(1));
	JASSNATIVE native = get_native(name.c_str());

	if (!native.is_valid()) {
		return 0;
	}

	int size = native.get_params().size();
	if (size > lua_gettop(l)) {
		return luaL_error(l, "function '%s' must have %d %s", name.c_str(), size, size > 1 ? "arguments" : "argument");
	}
	
	for (int i = 1; i <= size; i++) {
		if (lua_isnil(l, i)) {
			return luaL_error(l, "Argument number %d of function '%s' mustn't be equal to nil", i, name.c_str());
		}
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
				params[i - 1] = to_code(l, i, (UINT)lua_touserdata(l, 1));
			}

			break;
		case TYPE_BOOLEAN:
			params[i - 1] = (DWORD)lua_toboolean(l, i);

			break;
		case TYPE_HANDLE:
			params[i - 1] = (DWORD)lua_touserdata(l, i);

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
			params[i - 1] = to_string(cp1251_to_utf8(lua_tostring(l, i)).c_str());

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
	case TYPE_INTEGER:
		if (name == "GetUnitTypeId" || name == "GetSpellAbilityId" || name == "GetItemTypeId") {
			std::swap(((LPSTR)&result)[0], ((LPSTR)&result)[3]);
			std::swap(((LPSTR)&result)[1], ((LPSTR)&result)[2]);
			lua_pushlstring(l, (LPSTR)&result, 4);
		}
		else {
			lua_pushinteger(l, result);
		}

		break;
	case TYPE_CODE:
		lua_pushinteger(l, result);

		break;
	case TYPE_HANDLE:
		lua_pushlightuserdata(l, (PVOID)result);

		break;
	case TYPE_REAL:
		lua_pushnumber(l, from_real(result));

		break;
	case TYPE_STRING:
		lua_pushstring(l, utf8_to_cp1251(from_string(getJassMachine()->string_table->get(result))).c_str());

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

int lua_SetUnitArmor(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitArmor((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_GetUnitArmor(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetUnitArmor((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_GetUnitMaxLife(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetUnitMaxLife((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetUnitMaxLife(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitMaxLife((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_GetUnitMaxMana(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetUnitMaxMana((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetUnitMaxMana(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitMaxMana((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_GetUnitLifeRegen(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetUnitLifeRegen((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetUnitLifeRegen(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitLifeRegen((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_GetUnitManaRegen(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetUnitManaRegen((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetUnitManaRegen(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitManaRegen((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_GetUnitBaseDamage(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetUnitBaseDamage((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetUnitBaseDamage(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitBaseDamage((UINT)lua_touserdata(l, 1), (UINT)lua_tointeger(l, 2));

	return 0;
}

int lua_GetUnitAttackSpeed(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetUnitAttackSpeed((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetUnitAttackSpeed(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetUnitAttackSpeed((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_UnitResetAttackCooldown(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushboolean(l, UnitResetAttackCooldown((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_GetItemBaseNameById(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushstring(l, utf8_to_cp1251(GetItemBaseNameById(to_ID(lua_tostring(l, 1)))).c_str());

	return 1;
}

int lua_SetItemBaseNameById(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetItemBaseNameById(to_ID(lua_tostring(l, 1)), cp1251_to_utf8(lua_tostring(l, 2)).c_str());

	return 0;
}

int lua_GetItemBaseUbertipById(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushstring(l, utf8_to_cp1251(GetItemBaseUbertipById(to_ID(lua_tostring(l, 1)))).c_str());

	return 1;
}

int lua_SetItemBaseUbertipById(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetItemBaseUbertipById(to_ID(lua_tostring(l, 1)), cp1251_to_utf8(lua_tostring(l, 2)).c_str());

	return 0;
}

int lua_GetItemBaseIconPathById(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushstring(l, utf8_to_cp1251(GetItemBaseIconPathById(to_ID(lua_tostring(l, 1)))).c_str());

	return 1;
}

int lua_SetItemBaseIconPathById(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetItemBaseIconPathById(to_ID(lua_tostring(l, 1)), cp1251_to_utf8(lua_tostring(l, 2)).c_str());

	return 0;
}

int lua_GetMouseWorldPos(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	PVECTOR3 mousePos = GetMouseWorldPos();

	lua_pushnumber(l, mousePos->_x);
	lua_pushnumber(l, mousePos->_y);
	lua_pushnumber(l, mousePos->_z);

	return 3;
}

int lua_GetMouseWorldX(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetMouseWorldX());

	return 1;
}

int lua_GetMouseWorldY(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetMouseWorldY());

	return 1;
}

int lua_GetMouseWorldZ(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetMouseWorldZ());

	return 1;
}

int lua_GetEffectPos(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	PVECTOR3 objectPos = GetEffectPos((UINT)lua_touserdata(l, 1));

	lua_pushnumber(l, objectPos->_x);
	lua_pushnumber(l, objectPos->_y);
	lua_pushnumber(l, objectPos->_z);

	return 3;
}

int lua_GetEffectX(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetEffectPos((UINT)lua_touserdata(l, 1))->_x);

	return 1;
}

int lua_GetEffectY(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetEffectPos((UINT)lua_touserdata(l, 1))->_y);

	return 1;
}

int lua_GetEffectZ(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetEffectPos((UINT)lua_touserdata(l, 1))->_z);

	return 1;
}

int lua_SetEffectPos(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	UINT_PTR object = (UINT)lua_touserdata(l, 1);

	switch (lua_gettop(l))
	{
	case 2:
		SetEffectX(object, (float)lua_tonumber(l, 2));

		break;
	case 3:
		SetEffectX(object, (float)lua_tonumber(l, 2));
		SetEffectY(object, (float)lua_tonumber(l, 3));

		break;
	case 4:
		SetEffectPos(object, VECTOR3((float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3), (float)lua_tonumber(l, 4)));

		break;
	}

	return 0;
}

int lua_SetEffectX(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetEffectX((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetEffectY(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetEffectY((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetEffectZ(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetEffectZ((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

//--------------------------------------------------------

//--------------------------------------------------------
// FrameAPI

int lua_GetOriginFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushlightuserdata(l, (PVOID)GetOriginFrame((EOriginFrame)lua_tointeger(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

int lua_LoadTOCFile(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushboolean(l, LoadTOCFile(cp1251_to_utf8(lua_tostring(l, 1)).c_str()));

	return 1;
}

int lua_GetFrameByName(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushlightuserdata(l, (PVOID)GetFrameByName(cp1251_to_utf8(lua_tostring(l, 1)).c_str(), (UINT)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFrameParent(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushlightuserdata(l, (PVOID)GetFrameParent((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_GetFrameChildrenCount(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFrameChildrenCount((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_GetFrameChild(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushlightuserdata(l, (PVOID)GetFrameChild((UINT)lua_touserdata(l, 1), (UINT)lua_tointeger(l, 2)));

	return 1;
}

int lua_TriggerRegisterFrameEvent(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	TriggerRegisterFrameEvent((UINT)lua_touserdata(l, 1), (UINT)lua_touserdata(l, 2), (EFrameEvent)lua_tointeger(l, 3));

	return 0;
}

int lua_CreateFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushlightuserdata(l, (PVOID)CreateFrame(cp1251_to_utf8(lua_tostring(l, 1)).c_str(), (UINT)lua_touserdata(l, 2), (EFramePoint)lua_tointeger(l, 3), (EFramePoint)lua_tointeger(l, 4) /*(UINT)lua_tointeger(l, 5)*/));

	return 1;
}

int lua_SetFrameText(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameText((UINT)lua_touserdata(l, 1), cp1251_to_utf8(lua_tostring(l, 2)).c_str());

	return 0;
}

int lua_GetFrameText(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushstring(l, utf8_to_cp1251(GetFrameText((UINT)lua_touserdata(l, 1))).c_str());

	return 1;
}

int lua_SetFrameTextColor(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameTextColor((UINT)lua_touserdata(l, 1), (BYTE)lua_tointeger(l, 2), (BYTE)lua_tointeger(l, 3), (BYTE)lua_tointeger(l, 4), (BYTE)lua_tointeger(l, 5));

	return 0;
}

int lua_GetFrameTextHeight(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameTextHeight((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_SetFrameWidth(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameWidth((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameHeight(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameHeight((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameSize(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameSize((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3));

	return 0;
}

int lua_SetFrameScale(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameScale((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameAbsolutePoint(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameAbsolutePoint((UINT)lua_touserdata(l, 1), (EFramePoint)lua_tointeger(l, 2), (float)lua_tonumber(l, 3), (float)lua_tonumber(l, 4));

	return 0;
}

int lua_SetFramePoint(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFramePoint((UINT)lua_touserdata(l, 1), (EFramePoint)lua_tointeger(l, 2), (UINT)lua_touserdata(l, 3), (EFramePoint)lua_tointeger(l, 4), (float)lua_tonumber(l, 5), (float)lua_tonumber(l, 6));

	return 0;
}

int lua_GetFrameWidth(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameWidth((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_GetFrameHeight(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameHeight((UINT)lua_touserdata(l, 1)));

	return 1;
}

int lua_GetFramePointParent(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFramePointParent((UINT)lua_touserdata(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFramePointRelativePoint(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushinteger(l, GetFramePointRelativePoint((UINT)lua_touserdata(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFramePointX(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFramePointX((UINT)lua_touserdata(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetFramePointY(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFramePointY((UINT)lua_touserdata(l, 1), (EFramePoint)lua_tointeger(l, 2)));

	return 1;
}

int lua_GetTriggerFrame(lua_State* l) {
	lua_pushlightuserdata(l, (PVOID)GetTriggerFrame());

	return 1;
}

int lua_GetFrameValue(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	lua_pushnumber(l, GetFrameValue((UINT)lua_touserdata(l, 1)));

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

	SetFrameValue((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameMinMaxValue(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameMinMaxValue((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2), (float)lua_tonumber(l, 3));

	return 0;
}

int lua_SetFrameStepSize(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameStepSize((UINT)lua_touserdata(l, 1), (float)lua_tonumber(l, 2));

	return 0;
}

int lua_SetFrameTexture(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameTexture((UINT)lua_touserdata(l, 1), cp1251_to_utf8(lua_tostring(l, 2)).c_str(), lua_toboolean(l, 3));

	return 0;
}

int lua_SetFrameEnable(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameEnable((UINT)lua_touserdata(l, 1), lua_toboolean(l, 2));

	return 0;
}

int lua_ClickFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	ClickFrame((UINT)lua_touserdata(l, 1));

	return 0;
}

int lua_SetFrameModel(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameModel((UINT)lua_touserdata(l, 1), cp1251_to_utf8(lua_tostring(l, 2)).c_str(), (UINT)lua_tointeger(l, 3), (BOOL)lua_toboolean(l, 4));

	return 0;
}

int lua_DestroyFrame(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	DestroyFrame((UINT)lua_touserdata(l, 1));

	return 0;
}

int lua_SetFrameVisible(lua_State* l) {
	BOOL error = checkParams(l);
	if (error) {
		return error;
	}

	SetFrameVisible((UINT)lua_touserdata(l, 1), (BOOL)lua_toboolean(l, 2));

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

	SetFrameCheck((UINT)lua_touserdata(l, 1), (BOOL)lua_toboolean(l, 2));

	return 0;
}

//--------------------------------------------------------

int GetTrigger(lua_State* l) {
	lua_pushlightuserdata(l, (PVOID)GetTimerByHandle((UINT)lua_touserdata(l, 1)));

	return 1;
}

void lua_openMemHackAPI(lua_State* l) {
	lua_registerex(l, "GetUnitArmor", 1, lua_GetUnitArmor);
	lua_registerex(l, "SetUnitArmor", 2, lua_SetUnitArmor);
	lua_registerex(l, "GetUnitMaxLife", 1, lua_GetUnitMaxLife);
	lua_registerex(l, "SetUnitMaxLife", 2, lua_SetUnitMaxLife);
	lua_registerex(l, "GetUnitMaxMana", 1, lua_GetUnitMaxMana);
	lua_registerex(l, "SetUnitMaxMana", 2, lua_SetUnitMaxMana);
	lua_registerex(l, "GetUnitLifeRegen", 1, lua_GetUnitLifeRegen);
	lua_registerex(l, "SetUnitLifeRegen", 2, lua_SetUnitLifeRegen);
	lua_registerex(l, "GetUnitManaRegen", 1, lua_GetUnitManaRegen);
	lua_registerex(l, "SetUnitManaRegen", 2, lua_SetUnitManaRegen);
	lua_registerex(l, "GetUnitBaseDamage", 1, lua_GetUnitBaseDamage);
	lua_registerex(l, "SetUnitBaseDamage", 2, lua_SetUnitBaseDamage);
	lua_registerex(l, "GetUnitAttackSpeed", 1, lua_GetUnitAttackSpeed);
	lua_registerex(l, "SetUnitAttackSpeed", 2, lua_SetUnitAttackSpeed);
	lua_registerex(l, "UnitResetAttackCooldown", 1, lua_UnitResetAttackCooldown);
	lua_registerex(l, "GetItemBaseNameById", 1, lua_GetItemBaseNameById);
	lua_registerex(l, "SetItemBaseNameById", 2, lua_SetItemBaseNameById);
	lua_registerex(l, "GetItemBaseUbertipById", 1, lua_GetItemBaseUbertipById);
	lua_registerex(l, "SetItemBaseUbertipById", 2, lua_SetItemBaseUbertipById);
	lua_registerex(l, "GetItemBaseIconPathById", 1, lua_GetItemBaseIconPathById);
	lua_registerex(l, "SetItemBaseIconPathById", 2, lua_SetItemBaseIconPathById);
	lua_registerex(l, "GetMouseWorldPos", 0, lua_GetMouseWorldPos);
	lua_registerex(l, "GetMouseWorldX", 0, lua_GetMouseWorldX);
	lua_registerex(l, "GetMouseWorldY", 0, lua_GetMouseWorldY);
	lua_registerex(l, "GetMouseWorldZ", 0, lua_GetMouseWorldZ);
	lua_registerex(l, "GetEffectPos", 1, lua_GetEffectPos);
	lua_registerex(l, "GetEffectX", 1, lua_GetEffectX);
	lua_registerex(l, "GetEffectY", 1, lua_GetEffectY);
	lua_registerex(l, "GetEffectZ", 1, lua_GetEffectZ);
	lua_registerex(l, "SetEffectPos", 2, lua_SetEffectPos);
	lua_registerex(l, "SetEffectX", 2, lua_SetEffectX);
	lua_registerex(l, "SetEffectY", 2, lua_SetEffectY);
	lua_registerex(l, "SetEffectZ", 2, lua_SetEffectZ);
}

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