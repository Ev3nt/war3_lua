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

			LPSTR cmdline = GetCommandLine();
			size_t i;
			for (i = strlen(cmdline); i > 0 && cmdline[i] != '\"'; i--)
			{ }

			if (strstr(&cmdline[i + 1], "-debug"))
			{
				FILE* console;
				AllocConsole();
				freopen_s(&console, "CONOUT$", "w", stdout);
			}

			printf("%s\n%s\n", LUA_COPYRIGHT, WAR3_LUA);

			jmp(MakePtr(hGame, _TriggerRuntime), (DWORD)TriggerRuntime);
			call(MakePtr(hGame, _Main), Main);
		}
		else
			return FALSE;

	return TRUE;
}