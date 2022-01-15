#include "Hooks.h"

#include "Variables.h"
#include "Mem.h"
#include "LuaMachine.h"
#include <Storm.h>

DWORD __fastcall jassEntryPoint(DWORD a) {
	return (fastcall<DWORD>(MakePtr(gameBase, _jassEntryPointProc), a), startLua());
}

DWORD __stdcall getWarcraftID()
{
	return *(DWORD*)GAME_ID;
}

BOOL __fastcall isFrameValid(UINT frame, UINT, UINT eventcode) {
	for (const auto& event : frameEventHashTable) {
		for (const auto& eventframe : event.second) {
			if (eventframe.first == frame) {
				// our code
	
				return TRUE;
			}
		}
	}
	
	if (!*(DWORD*)(frame + 8)) {
		return FALSE;
	}

	return thiscall<BOOL>(MakePtr(gameBase, 0x62a1c0), *(DWORD*)(frame + 8), eventcode, 0);
}

BOOL __fastcall frameEventObserver(UINT frame, UINT, DWORD eventaddress) {
	if (frameEventHashTable[(EFrameEvent)(*(DWORD*)(eventaddress + 8) - 0x40090063)].find(frame) != frameEventHashTable[(EFrameEvent)(*(DWORD*)(eventaddress + 8) - 0x40090063)].end()) {
		if (!running) {
			return FALSE;
		}

		lua_State* l = getMainLuaState();
		getFunctionByRef(l, frameEventHashTable[(EFrameEvent)(*(DWORD*)(eventaddress + 8) - 0x40090063)][frame]);
		lua_State* thread = createThread(l, -1);
		lua_xmove(l, thread, 1);
		
		int res;
		switch (lua_resume(thread, l, 0, &res)) {
		case LUA_ERRRUN:
			lua_throwerr(thread);
		
			break;
		}

		return TRUE;
	}

	return thiscall<BOOL>(*(DWORD*)(*(DWORD*)frame + 0x14), frame, *(DWORD*)(eventaddress + 8), eventaddress);
}