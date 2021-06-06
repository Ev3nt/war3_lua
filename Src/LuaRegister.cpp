#include "LuaRegister.h"

#include "Warcraft.h"
#include "JassNatives.h"

LUA lua_jCall(lua_State* l)
{
	LPCSTR name = lua_tostring(l, lua_upvalueindex(1));
	JASSNATIVE native = get_native(name);

	if (!native.is_valid())
	{
		printf("[LUA] Warning: Jass function with name %s doesn't exist.\n", name);

		return 0;
	}

	{
		std::vector<JASS_TYPE> params = native.get_params();
		if ((int)params.size() > lua_gettop(l))
			return 0;
	}

	std::vector<DWORD> temp_params;
	std::vector<DWORD> params;
	UINT i = 1;
	for (const auto& e : native.get_params())
	{
		switch (e)
		{
		case TYPE_CODE:
			if (lua_isinteger(l, i))
				params.push_back((DWORD)lua_tointeger(l, i));
			else if (lua_isfunction(l, i))
				params.push_back(to_Code(l, i));

			break;
		case TYPE_BOOLEAN:
			params.push_back((DWORD)lua_toboolean(l, i));

			break;
		case TYPE_HANDLE:
			params.push_back((DWORD)lua_tointeger(l, i));

			break;
		case TYPE_INTEGER:
			if (lua_isinteger(l, i))
				params.push_back((DWORD)lua_tointeger(l, i));
			else
				params.push_back(to_ID(lua_tostring(l, i)));

			break;
		case TYPE_REAL:
			temp_params.push_back(to_jReal((float)lua_tonumber(l, i)));
			params.push_back((DWORD) & (temp_params[temp_params.size() - 1]));

			break;
		case TYPE_STRING:
			params.push_back(to_jString(lua_tostring(l, i)));

			break;
		default:
			params.push_back(0);

			break;
		}

		i++;
	}

	DWORD result = native.call(params);

	switch (native.get_rettype())
	{
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
		lua_pushstring(l, from_jString(GetJassMachine()->string_table->get(result)));

		break;
	}

	return native.get_rettype() != TYPE_NOTHING ? 1 : 0;
}

LUA lua_get(lua_State* l)
{
	lua_pushstring(l, lua_tostring(l, 2));
	lua_pushcclosure(l, lua_jCall, 1);

	return 1;
}

LUA lua_opennatives(lua_State* l)
{
	lua_newtable(l);
	lua_newtable(l);

	lua_pushstring(l, "__index");
	lua_pushcclosure(l, lua_get, 0);
	lua_rawset(l, -3);

	lua_setmetatable(l, -2);

	return 1;
}

//-------------------------------------------------------------

void lua_open_jassnatives(lua_State* l)
{
	lua_preload(l, "jass.natives", lua_opennatives);
}