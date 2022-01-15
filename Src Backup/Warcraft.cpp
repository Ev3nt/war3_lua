#include "Warcraft.h"

#include "Variables.h"
#include "fcalls.h"
#include "Mem.h"

PJASS_INSTANCE getJassMachine(DWORD index) {
	DWORD jass_thread = *(DWORD*)(*(DWORD*)(getInstance(5) + 0x90) + index * 4);

	return jass_thread ? (PJASS_INSTANCE)jass_thread : NULL;
}

PJASS_INSTANCE getJassInstance() {
	DWORD instance = getInstance(5);

	return *(DWORD*)(instance + 0x14) ? *(PJASS_INSTANCE*)(*(DWORD*)(instance + 0xc) + *(DWORD*)(instance + 0x14) * 4 - 4) : NULL;
}

DWORD getInstance(DWORD index) {
	return fastcall<DWORD>(MakePtr(gameBase, _getInstanceProc), index);
}

CGameUI* GetGameUI(UINT unknown0, UINT unknown1) {
	return fastcall<CGameUI*>(MakePtr(gameBase, _getGameUI), unknown0, unknown1);
}

CGameWar3* GetGameWar3(UINT unknown0) {
	return fastcall<CGameWar3*>(MakePtr(gameBase, _getGameWar3), unknown0);
}