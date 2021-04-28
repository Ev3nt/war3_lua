#include <Windows.h>
#include <vector>

#include "Variables.h"
#include "Hooks.h"

#include "Mem.h"

BOOL APIENTRY DllMain(HMODULE hModule, UINT ul_reason_for_call, LPVOID lpReserve)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		if (hGame)
		{
			DisableThreadLibraryCalls(hModule);

			FILE* console;
			AllocConsole();
			freopen_s(&console, "CONOUT$", "w", stdout);

			jmp(MakePtr(hGame, 0x44b6a0), (DWORD)DoTrigger);
			call(MakePtr(hGame, _Main), Main);
		}
		else
			return FALSE;

	return TRUE;
}