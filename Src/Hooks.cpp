#include "Hooks.h"
#include "Variables.h"
#include "Lua.h"
#include "Mem.h"

BOOL __fastcall DoTrigger(DWORD a1, DWORD index, DWORD a3, DWORD result, DWORD a5, DWORD a6, DWORD a7)
{
	DWORD trigger;
	DWORD table_offset;
	DWORD table;
	PLUA_TRIGGER lua_trigger;
	__asm {
		mov edi, index
	}
	table_offset = reinterpret_cast<DWORD(__cdecl*)()>(MakePtr(hGame, 0x44b2e0))();
	lua_trigger = (PLUA_TRIGGER)index;
	table = *(DWORD*)(*(DWORD*)(table_offset + 0x2888) + 8);

	for (const auto& _trigger : g_LuaTriggers)
		if (lua_trigger == _trigger)
		{
			DWORD retval = 0;
			lua_pushvalue(lua_trigger->lua, -1);

			switch (lua_trigger->type)
			{
			case LUA_TRIGGER_CODE:
				retval = !lua_pcall(lua_trigger->lua, 0, 0, 0);

				break;
			case LUA_CONDITION_CODE:

				retval = !lua_pcall(lua_trigger->lua, 0, 1, 0);;
				*(DWORD*)result = lua_toboolean(lua_trigger->lua, -1);
				lua_pop(lua_trigger->lua, 1);

				break;
			default:
				lua_pop(lua_trigger->lua, 1);

				break;
			}

			return retval;
		}

	trigger = *(DWORD*)(table + index * 4);

	return reinterpret_cast<DWORD(__fastcall*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD)>(MakePtr(hGame, 0x45fa30))(table_offset, 0, trigger, a3, result, a5, a6, a7);
}

DWORD _fastcall Main(DWORD a1)
{
	DWORD result = reinterpret_cast<DWORD(_fastcall*)(DWORD)>(MakePtr(hGame, _MainProc))(a1);

	RunLua();

	
	HANDLE hMpq = *(HANDLE*)MakePtr(hGame, 0xaae788);
	char buffer[MAX_PATH];

	reinterpret_cast<BOOL(CALLBACK*)(HANDLE, LPSTR, int)>(GetProcAddress(0, (LPCSTR)275))(hMpq, buffer, MAX_PATH);
	
	printf("Map name: %s\n", buffer);

	return result;
}