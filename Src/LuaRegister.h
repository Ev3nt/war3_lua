#pragma once

#include <Windows.h>

#include "Variables.h"

typedef int LUA;

void lua_opencfunctions(lua_State* l);

//------------------------C Functions

LUA lua_CreateTimer(lua_State* l);
LUA lua_TimerStart(lua_State* l);
LUA lua_CreateUnit(lua_State* l);
LUA lua_Player(lua_State* l);
LUA lua_DisplayTimedTextToPlayer(lua_State* l);
LUA lua_ConvertPlayerEvent(lua_State* l);
LUA lua_TriggerRegisterPlayerEvent(lua_State* l);
LUA lua_TriggerRegisterPlayerChatEvent(lua_State* l);
LUA lua_Condition(lua_State* l);
LUA lua_TriggerAddCondition(lua_State* l);
LUA lua_CreateTrigger(lua_State* l);
LUA lua_TriggerAddAction(lua_State* l);
LUA lua_GetPlayerName(lua_State* l);