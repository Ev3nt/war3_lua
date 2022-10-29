#include "pch.h"
#include "LuaFunctions.h"
#include "JassNatives.h"
#include "LuaMachine.h"
#include "JassMachine.h"
#include "EasyStormLib/EasyStormLib.h"

#define lua_registerJassNative(L, n, f) (lua_pushstring(L, (n)), lua_pushcclosure(L, (f), 1), lua_setglobal(L, (n)))

std::map<std::string, bool> destroyers = {
	{"DestroyTimer", true},
	{"DestroyGroup", true},
	{"DestroyForce", true},
	{"DestroyTrigger", true},
	{"DestroyCondition", true},
	{"DestroyFiler", true},
	{"DestroyBoolExpr", true},
	{"DestroyFogModifier", true},
	{"DialogDestroy", true},
	{"DestroyUnitPool", true},
	{"DestroyItemPool", true},
	{"DestroyTextTag", true},
	{"DestroyQuest", true},
	{"DestroyDefeatCondition", true},
	{"DestroyTimerDialog", true},
	{"DestroyLeaderboard", true},
	{"DestroyMultiboard", true},
	{"DestroyEffect", true},
	{"DestroyLightning", true},
	{"DestroyImage", true},
	{"DestroyUbersplat", true},

	{"RemoveRect", true},
	{"RemoveRegion", true},
	{"RemoveLocation", true},
	{"RemoveDestructable", true},
	{"RemoveItem", true},
	{"RemoveUnit", true},
	{"RemoveWeatherEffect", true}
};

std::map<std::string, std::string> inheritance = {
	{ "agent"			   , "handle" },
	{ "event"              , "agent" },
	{ "player"             , "agent" },
	{ "widget"             , "agent" },
	{ "unit"               , "widget" },
	{ "destructable"       , "widget" },
	{ "item"               , "widget" },
	{ "ability"            , "agent" },
	{ "buff"               , "ability" },
	{ "force"              , "agent" },
	{ "group"              , "agent" },
	{ "trigger"            , "agent" },
	{ "triggercondition"   , "agent" },
	{ "triggeraction"      , "handle" },
	{ "timer"              , "agent" },
	{ "location"           , "agent" },
	{ "region"             , "agent" },
	{ "rect"               , "agent" },
	{ "boolexpr"           , "agent" },
	{ "sound"              , "agent" },
	{ "conditionfunc"      , "boolexpr" },
	{ "filterfunc"         , "boolexpr" },
	{ "unitpool"           , "handle" },
	{ "itempool"           , "handle" },
	{ "race"               , "handle" },
	{ "alliancetype"       , "handle" },
	{ "racepreference"     , "handle" },
	{ "gamestate"          , "handle" },
	{ "igamestate"         , "gamestate" },
	{ "fgamestate"         , "gamestate" },
	{ "playerstate"        , "handle" },
	{ "playerscore"        , "handle" },
	{ "playergameresult"   , "handle" },
	{ "unitstate"          , "handle" },
	{ "aidifficulty"       , "handle" },
	{ "eventid"            , "handle" },
	{ "gameevent"          , "eventid" },
	{ "playerevent"        , "eventid" },
	{ "playerunitevent"    , "eventid" },
	{ "unitevent"          , "eventid" },
	{ "limitop"            , "eventid" },
	{ "widgetevent"        , "eventid" },
	{ "dialogevent"        , "eventid" },
	{ "unittype"           , "handle" },
	{ "gamespeed"          , "handle" },
	{ "gamedifficulty"     , "handle" },
	{ "gametype"           , "handle" },
	{ "mapflag"            , "handle" },
	{ "mapvisibility"      , "handle" },
	{ "mapsetting"         , "handle" },
	{ "mapdensity"         , "handle" },
	{ "mapcontrol"         , "handle" },
	{ "playerslotstate"    , "handle" },
	{ "volumegroup"        , "handle" },
	{ "camerafield"        , "handle" },
	{ "camerasetup"        , "handle" },
	{ "playercolor"        , "handle" },
	{ "placement"          , "handle" },
	{ "startlocprio"       , "handle" },
	{ "raritycontrol"      , "handle" },
	{ "blendmode"          , "handle" },
	{ "texmapflags"        , "handle" },
	{ "effect"             , "agent" },
	{ "effecttype"         , "handle" },
	{ "weathereffect"      , "handle" },
	{ "terraindeformation" , "handle" },
	{ "fogstate"           , "handle" },
	{ "fogmodifier"        , "agent" },
	{ "dialog"             , "agent" },
	{ "button"             , "agent" },
	{ "quest"              , "agent" },
	{ "questitem"          , "agent" },
	{ "defeatcondition"    , "agent" },
	{ "timerdialog"        , "agent" },
	{ "leaderboard"        , "agent" },
	{ "multiboard"         , "agent" },
	{ "multiboarditem"     , "agent" },
	{ "trackable"          , "agent" },
	{ "gamecache"          , "agent" },
	{ "version"            , "handle" },
	{ "itemtype"           , "handle" },
	{ "texttag"            , "handle" },
	{ "attacktype"         , "handle" },
	{ "damagetype"         , "handle" },
	{ "weapontype"         , "handle" },
	{ "soundtype"          , "handle" },
	{ "lightning"          , "handle" },
	{ "pathingtype"        , "handle" },
	{ "image"              , "handle" },
	{ "ubersplat"          , "handle" },
	{ "hashtable"          , "agent" }
};

namespace LuaFunctions {
	bool IsChild(const std::string& maintype, std::string childtype) {
		do {
			if (maintype == childtype) {
				return true;
			}

			childtype = inheritance[childtype];
		} while (!childtype.empty());

		return false;
	}

	//--------------------------------------------------------
	// JassNatives

	int lua_invokeNative(lua_State* l) {
		std::string name = lua_tostring(l, lua_upvalueindex(1));
		Jass::JASSNATIVE native = Jass::GetNative(name);

		if (!native.IsValid()) {
			return 0;
		}
		
		std::size_t size = native.GetParams().size();
		std::vector<float> floats;
		std::vector<UINT> params;
		params.resize(size);
		UINT i = 1;

		// Lua parameters -> Jass parameters
		for (const auto& type : native.GetParams()) {
			if (isupper(type[0])) {
				switch (type[0]) {
				case 'C':
					if (lua_isfunction(l, i)) {
						params[i - 1] = Jass::ToCode(l, i);
					}
					else if (luaL_testudata(l, i, "code")) {
						params[i - 1] = *(DWORD*)lua_touserdata(l, i);
					}
					else {
						return luaL_typeerror(l, i, "function or code");
					}

					break;
				case 'B':
					if (lua_isboolean(l, i)) {
						params[i - 1] = (DWORD)lua_toboolean(l, i);
					}
					else {
						return luaL_typeerror(l, i, "boolean");
					}

					break;
				case 'I':
					if (lua_isinteger(l, i)) {
						params[i - 1] = (DWORD)lua_tointeger(l, i);
					}
					/*else if (lua_isstring(l, i) && strlen(lua_tostring(l, i)) == 4) {
						params[i - 1] = Jass::ToID(lua_tostring(l, i));
					}*/
					else {
						return luaL_typeerror(l, i, "integer");
					}

					break;
				case 'R': {
					if (lua_isnumber(l, i)) {
						floats.push_back((float)lua_tonumber(l, i));
						params[i - 1] = (DWORD)&floats[floats.size() - 1];
					}
					else {
						return luaL_typeerror(l, i, "number");
					}

					break;
				}
				case 'S':
					if (lua_isstring(l, i)) {
						params[i - 1] = (UINT)&JassMachine::GetJassMachine()->string_table->GetRCString(Jass::ToString(lua_tostring(l, i)));
					}
					else {
						return luaL_typeerror(l, i, "string");
					}

					break;
				default:
					params[i - 1] = NULL;

					break;
				}
			}
			else {
				if (!lua_isnil(l, i)) {
					if (luaL_getmetafield(l, i, "__name") != LUA_TSTRING) {
						return luaL_typeerror(l, i, type.c_str());
					}

					if (developerMode) {
						std::string metatype = std::string(lua_tostring(l, -1));

						if (!IsChild(type, metatype)) {
							luaL_where(l, 1);
							std::string where = lua_tostring(l, -1);
							lua_pop(l, 1);

							LuaMachine::lua_throwWarning(l, Utils::format("%s bad argument #%d to '%s' (%s expected, got %s)", where.c_str(), i, name.c_str(), type.c_str(), metatype.c_str()));

						}
					}

					lua_pop(l, 1);

					if (luaL_testudata(l, i, "code")) {
						return luaL_typeerror(l, i, type.c_str());
					}

					params[i - 1] = *(DWORD*)lua_touserdata(l, i);
				}
			}

			i++;
		}

		if (name == "Player" && (int)params[0] < 0) {
			return luaL_error(l, "player expected positive index, received: %d", params[0]);
		}

		BOOL result = native.Invoke(params.data(), size);

		// Jass return -> Lua return
		std::string return_type = native.GetReturnType();
		if (isupper(return_type[0])) {
			switch (return_type[0]) {
			case 'B':
				lua_pushboolean(l, result);

				break;
			case 'I':
				lua_pushinteger(l, result);

				break;
			case 'C':
				lua_pushinteger(l, result);

				break;
			case 'R':
				lua_pushnumber(l, Jass::FromReal(result));

				break;
			case 'S':
				lua_pushstring(l, JassMachine::GetJassMachine()->string_table->GetString(result));
				//lua_pushstring(l, Jass::FromString(JassMachine::GetJassMachine()->string_table->Get(result)));

				break;
			default:
				return 0;
			}
		}
		else {
			LuaMachine::GetUserdataByHandle(l, result, return_type.c_str());
			//result ? *(DWORD*)lua_newuserdata(l, sizeof(DWORD)) = result, luaL_setmetatable(l, return_type.c_str()) : lua_pushnil(l);
		}

		return 1;
	}

	//--------------------------------------------------------

	/*int lua_handleequal(lua_State* l) {
		PDWORD param1 = (PDWORD)lua_touserdata(l, 1);
		PDWORD param2 = (PDWORD)lua_touserdata(l, 2);

		lua_pushboolean(l, (param1 ? *param1 : NULL) == (param2 ? *param2 : NULL));

		return 1;
	}*/

	int lua_handletostring(lua_State* l) {
		luaL_getmetafield(l, 1, "__name");

		UINT handle = *(UINT*)lua_touserdata(l, 1);

		std::string string = !developerMode ? 
							 Utils::format("%s: %08X", lua_tostring(l, 2), handle) : 
							 Utils::format("%s: %08X | %08X", lua_tostring(l, 2), handle, Warcraft::ConvertHandle(handle));

		lua_pop(l, 1);
	
		lua_pushstring(l, string.c_str());
	
		return 1;
	}

	int IdToString(lua_State* l) {
		if (lua_isinteger(l, 1)) {
			DWORD id = (DWORD)lua_tointeger(l, 1);
			std::reverse(&(((LPSTR)&id)[0]), &(((LPSTR)&id)[4]));
			lua_pushlstring(l, (LPSTR)&id, 4);
		}
		else {
			return luaL_typeerror(l, 1, "integer");
		}


		return 1;
	}

	int StringToId(lua_State* l) {
		if (lua_isstring(l, 1)) {
			lua_pushinteger(l, Jass::ToID(lua_tostring(l, 1)));
		}
		else {
			return luaL_typeerror(l, 1, "string");
		}

		return 1;
	}

	int FourCC(lua_State* l) {
		if (lua_isinteger(l, 1)) {
			IdToString(l);
		}
		else if (lua_isstring(l, 1)) {
			StringToId(l);
		}
		else {
			return luaL_typeerror(l, 1, "string or integer");
		}

		return 1;
	}

	/*int IsHandleExists(lua_State* l) {
		if (lua_isuserdata(l, 1)) {
			lua_pushboolean(l, *(DWORD*)lua_touserdata(l, 1) != NULL);
		}
		else {
			return luaL_typeerror(l, 1, "handle");
		}

		return 1;
	}*/

	void lua_openJassNatives(lua_State* l) {
		Jass::JassNativesParse();

		for (const auto& type : LuaMachine::handlemetatypes) {
			if (luaL_newmetatable(l, type.first.c_str())) {
				/*lua_pushcfunction(l, lua_handleequal);
				lua_setfield(l, -2, "__eq");*/

				lua_pushcfunction(l, lua_handletostring);
				lua_setfield(l, -2, "__tostring");

				lua_pushboolean(l, false);
				lua_setfield(l, -2, "__metatable");

				lua_pop(l, 1);
			}
		}

		for (const auto& native : Jass::jassnatives) {
			lua_registerJassNative(l, native.first.c_str(), lua_invokeNative);
		}

		lua_register(l, "IdToString", IdToString);
		lua_register(l, "StringToId", StringToId);
		lua_register(l, "FourCC", FourCC);
		//lua_register(l, "IsHandleExists", IsHandleExists);
	}

	int lua_getJassArrayElement(lua_State* l) {
		luaL_getmetafield(l, 1, "array");
		JassMachine::PJASS_VARIABLE var = (JassMachine::PJASS_VARIABLE)lua_tointeger(l, -1);
		lua_pop(l, 1);

		if (!var) {
			return 0;
		}

		JassMachine::PJASS_ARRAY arr = (JassMachine::PJASS_ARRAY)var->value;
		UINT index = (UINT)lua_tointeger(l, 2);

		if (index >= arr->list.max) {
			return 0;
		}

		switch ((OPCODE_VARIABLE)var->retType)
		{
			case OPCODE_VARIABLE::TYPE_INTEGER_ARRAY: {
				lua_pushinteger(l, arr->list.value[index]);

				break;
			}
			case OPCODE_VARIABLE::TYPE_REAL_ARRAY: {
				lua_pushnumber(l, Jass::FromReal(arr->list.value[index]));

				break;
			}
			case OPCODE_VARIABLE::TYPE_STRING_ARRAY: {
				lua_pushstring(l, JassMachine::GetJassMachine()->string_table->GetString(arr->list.value[index]));

				break;
			}
			case OPCODE_VARIABLE::TYPE_HANDLE_ARRAY: {
				LuaMachine::GetUserdataByHandle(l, arr->list.value[index], "handle");

				break;
			}
			case OPCODE_VARIABLE::TYPE_BOOLEAN_ARRAY: {
				lua_pushboolean(l, arr->list.value[index]);

				break;
			}

			default: {
				lua_pushnil(l);

				break;
			}
		}

		return 1;
	}

	int lua_getJassArrayLenght(lua_State* l) {
		luaL_getmetafield(l, 1, "array");
		JassMachine::PJASS_VARIABLE var = (JassMachine::PJASS_VARIABLE)lua_tointeger(l, -1);
		lua_pop(l, 1);

		if (!var) {
			return 0;
		}

		lua_pushinteger(l, ((JassMachine::PJASS_ARRAY)var->value)->list.max);

		return 1;
	}

	int lua_getJassVariable(lua_State* l) {
		JassMachine::PJASS_INSTANCE jvm = JassMachine::GetJassMachine();
		if (!jvm) {
			return 0;
		}

		JassMachine::PJASS_VARIABLE var = JassMachine::GetVariableDataNodeByName(jvm->script_table, lua_tostring(l, 2));

		if (!var) {
			return 0;
		}

		OPCODE_VARIABLE type = (OPCODE_VARIABLE)var->retType;
		if (type < OPCODE_VARIABLE::TYPE_INTEGER_ARRAY) {
			switch (type)
			{
				case OPCODE_VARIABLE::TYPE_CODE: {
					LuaMachine::GetUserdataByHandle(l, var->value, "code");

				break;
			}
				case OPCODE_VARIABLE::TYPE_INTEGER: {
					lua_pushinteger(l, var->value);

				break;
			}
				case OPCODE_VARIABLE::TYPE_REAL: {
					lua_pushnumber(l, Jass::FromReal(var->value));

				break;
			}
				case OPCODE_VARIABLE::TYPE_STRING: {
					lua_pushstring(l, JassMachine::GetJassMachine()->string_table->GetString(var->value));

				break;
			}
				case OPCODE_VARIABLE::TYPE_HANDLE: {
				LuaMachine::GetUserdataByHandle(l, var->value, "handle");

				break;
			}
				case OPCODE_VARIABLE::TYPE_BOOLEAN: {
					lua_pushboolean(l, var->value);

				break;
			}

				default: {
					lua_pushnil(l);

					break;
				}
			}
		}
		else {
			lua_newtable(l);

			lua_newtable(l);
			lua_pushinteger(l, (DWORD)var);
			lua_setfield(l, -2, "array");
			// __index
			lua_pushcfunction(l, lua_getJassArrayElement);
			lua_setfield(l, -2, "__index");
			// __len
			lua_pushcfunction(l, lua_getJassArrayLenght);
			lua_setfield(l, -2, "__len");
			// __metatable
			lua_pushboolean(l, false);
			lua_setfield(l, -2, "__metatable");

			lua_setmetatable(l, -2);
		}

		return 1;
	}

	void lua_openJassVariables(lua_State* l) {
		/*JassMachine::PJASS_INSTANCE jvm = JassMachine::GetJassMachine();
		if (!jvm) {
			return;
		}

		JassMachine::PSCRIPT_DATA_TABLE scripts = jvm->script_table;
		if (!scripts) {
			return;
		}

		JassMachine::PJASS_VARIABLE var;
		for (var = scripts->variable; (int)var > NULL; var = var->next) {
			LuaMachine::GetUserdataByHandle(l, (DWORD)var, "pJassVariable");
			lua_setglobal(l, var->name);
		}

		return;*/

		//lua_newtable(l);
		//lua_pushvalue(l, -1);
		//lua_setglobal(l, "jass");

		lua_getglobal(l, "_G");

		lua_newtable(l);
		// __index
		lua_pushcfunction(l, lua_getJassVariable);
		lua_setfield(l, -2, "__index");
		// __metatable
		lua_pushboolean(l, false);
		lua_setfield(l, -2, "__metatable");

		lua_setmetatable(l, -2);
		lua_pop(l, 1);

		
	}

	//--------------------------------------------------------

	int lua_GetMapFileName(lua_State* l) {
		if (lua_isboolean(l, 1)) {
			Storm::Archive map;
			map.Connect(*(HANDLE*)pOffsets[(UINT)Offset::LastPlayedMap]);
			std::string name = map.GetArchiveName();

			if (!lua_toboolean(l, 1)) {
				size_t pathSlash = name.find_last_of('\\');
				pathSlash != std::string::npos ? name = name.substr(pathSlash + 1) : NULL;
			}

			lua_pushstring(l, name.c_str());
		}
		else {
			return luaL_typeerror(l, 1, "boolean");
		}

		return 1;
	}

	void lua_openExternalFunctions(lua_State* l) {
		lua_register(l, "GetMapFileName", lua_GetMapFileName);
	}
}