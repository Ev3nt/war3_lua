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

//BOOL __fastcall glueButtonOnClick(UINT frame, UINT, BOOL unknown1) {
//	if (thiscall<bool>(MakePtr(gameBase, 0x62a580), frame, 0x40090064)) {
//		*(DWORD*)MakePtr(gameBase, 0xa9a7c4) = unknown1;
//		*(DWORD*)MakePtr(gameBase, 0xa9a7c8) = frame;
//		*(DWORD*)MakePtr(gameBase, 0xa9a7bc) = 0x40090064;
//
//		return thiscall<BOOL>(*(DWORD*)(*(DWORD*)frame + 0x10), frame, MakePtr(gameBase, 0xa9a7b4));
//	}
//	else {
//		Beep(500, 200);
//	}
//
//	return FALSE;
//}