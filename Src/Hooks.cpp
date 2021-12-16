#include "Hooks.h"

#include "Variables.h"
#include "Mem.h"
#include "LuaMachine.h"

DWORD __fastcall jassEntryPoint(DWORD a) {
	return (fastcall<DWORD>(MakePtr(gameBase, _jassEntryPointProc), a), startLua());
}