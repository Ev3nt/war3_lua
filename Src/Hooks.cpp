#include "Hooks.h"

#include "Variables.h"
#include "Mem.h"
#include "LuaMachine.h"

DWORD __fastcall JassEntryPoint(DWORD a)
{
	DWORD result = reinterpret_cast<DWORD(__fastcall*)(DWORD)>(MakePtr(hGame, _JassEntryPointProc))(a);

	StartLua();

	return result;
}