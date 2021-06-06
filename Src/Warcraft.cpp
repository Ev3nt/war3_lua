#include "Warcraft.h"

#include "Variables.h"
#include "Mem.h"

PJASS_INSTANCE GetJassMachine(DWORD index)
{
	DWORD jass_thread = *(DWORD*)(*(DWORD*)(GetInstance(5) + 0x90) + index * 4);
	return jass_thread ? (PJASS_INSTANCE)jass_thread : NULL;
}

PJASS_INSTANCE GetJassInstance()
{
	DWORD instance = GetInstance(5);
	return *(DWORD*)(instance + 0x14) ? *(PJASS_INSTANCE*)(*(DWORD*)(instance + 0xc) + *(DWORD*)(instance + 0x14) * 4 - 4) : NULL;
}

DWORD GetInstance(DWORD index)
{
	return reinterpret_cast<DWORD(__fastcall*)(DWORD)>(MakePtr(hGame, _GetInstanceProc))(index);
}