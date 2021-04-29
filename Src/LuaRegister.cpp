#include "LuaRegister.h"
#include "Jass.h"

void lua_opencfunctions(lua_State* l)
{
	lua_register(l, "CreateTimer", lua_CreateTimer);
	lua_register(l, "TimerStart", lua_TimerStart);
	lua_register(l, "DisplayTimedTextToPlayer", lua_DisplayTimedTextToPlayer);
	lua_register(l, "Player", lua_Player);
	lua_register(l, "CreateUnit", lua_CreateUnit);
	lua_register(l, "ConvertPlayerEvent", lua_ConvertPlayerEvent);
	lua_register(l, "TriggerRegisterPlayerEvent", lua_TriggerRegisterPlayerEvent);
	lua_register(l, "TriggerRegisterPlayerChatEvent", lua_TriggerRegisterPlayerChatEvent);
	lua_register(l, "CreateTrigger", lua_CreateTrigger);
	lua_register(l, "TriggerAddAction", lua_TriggerAddAction);
	lua_register(l, "Condition", lua_Condition);
	lua_register(l, "TriggerAddCondition", lua_TriggerAddCondition);
	lua_register(l, "GetPlayerName", lua_GetPlayerName);
}

//------------------------C Functions

LUA lua_CreateTimer(lua_State* l)
{
	lua_pushinteger(l, CreateTimer());

	return 1;
}

LUA lua_TimerStart(lua_State* l)
{
	jReal timeout = to_jReal((float)lua_tointeger(l, 2));

	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 4);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	TimerStart((HTIMER)lua_tointeger(l, 1), &timeout, lua_toboolean(l, 3), (jCode)trigger);

	return 0;
}

LUA lua_CreateUnit(lua_State* l)
{
	jReal x = to_jReal((float)lua_tointeger(l, 3));
	jReal y = to_jReal((float)lua_tointeger(l, 4));
	jReal face = to_jReal((float)lua_tointeger(l, 5));

	lua_pushinteger(l, CreateUnit((jInteger)lua_tointeger(l, 1), to_ID(lua_tostring(l, 2)), &x, &y, &face));

	return 1;
}

LUA lua_Player(lua_State* l)
{
	lua_pushinteger(l, Player((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_DisplayTimedTextToPlayer(lua_State* l)
{
	jReal x = to_jReal((float)lua_tonumber(l, 2));
	jReal y = to_jReal((float)lua_tonumber(l, 3));
	jReal duration = to_jReal((float)lua_tonumber(l, 4));

	DisplayTimedTextToPlayer((jInteger)lua_tointeger(l, 1), &x, &y, &duration, to_jString(lua_tostring(l, 5)));

	return 0;
}

LUA lua_ConvertPlayerEvent(lua_State* l)
{
	lua_pushinteger(l, ConvertPlayerEvent((jInteger)lua_tointeger(l, 1)));

	return 1;
}

LUA lua_TriggerRegisterPlayerEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterPlayerEvent((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), (HPLAYEREVENT)lua_tointeger(l, 3)));

	return 1;
}

LUA lua_TriggerRegisterPlayerChatEvent(lua_State* l)
{
	lua_pushinteger(l, TriggerRegisterPlayerChatEvent((jTrigger)lua_tointeger(l, 1), (HPLAYER)lua_tointeger(l, 2), to_jString(lua_tostring(l, 3)), lua_toboolean(l, 4)));

	return 1;
}

LUA lua_CreateTrigger(lua_State* l)
{
	lua_pushinteger(l, CreateTrigger());

	return 1;
}

LUA lua_Condition(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_CONDITION_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 1);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	lua_pushinteger(l, Condition((jCode)trigger));

	return 1;
}

LUA lua_TriggerAddCondition(lua_State* l)
{
	lua_pushinteger(l, TriggerAddCondition((jTrigger)lua_tointeger(l, 1), (HBOOLEXPR)lua_tointeger(l, 2)));

	return 1;
}

LUA lua_TriggerAddAction(lua_State* l)
{
	PLUA_TRIGGER trigger = new LUA_TRIGGER;
	trigger->parent = l;
	trigger->lua = lua_newthread(trigger->parent);
	trigger->type = TYPES::LUA_TRIGGER_CODE;
	lua_pop(trigger->parent, 1);
	lua_pushvalue(trigger->parent, 2);
	lua_xmove(trigger->parent, trigger->lua, 1);

	g_LuaTriggers.push_back(trigger);

	lua_pushinteger(l, TriggerAddAction((jTrigger)lua_tointeger(l, 1), (jCode)trigger));

	return 1;
}

LUA lua_GetPlayerName(lua_State* l)
{
	lua_pushstring(l, GetPlayerName((jInteger)lua_tointeger(l, 1)));

	return 1;
}