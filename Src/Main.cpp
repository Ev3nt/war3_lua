#include <Windows.h>
#include <iostream>

#include "Variables.h"
#include "Mem.h"
#include "Hooks.h"
#include "JassMachine.h"

BOOL APIENTRY DllMain(HMODULE hModule, UINT ul_reason_for_call, LPVOID lpReserve)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		if (gameBase) {
			DisableThreadLibraryCalls(hModule);

			LPSTR cmdline = GetCommandLine();
			size_t i;
			for (i = strlen(cmdline); i > 0 && cmdline[i] != '\"'; i--);

			if (strstr(&cmdline[i + 1], "-debug")) {
				FILE* console;
				AllocConsole();
				freopen_s(&console, "CONOUT$", "w", stdout);
				SetConsoleTitle("Lua Debug");
			}

			printf("%s\n%s\n", LUA_COPYRIGHT, WAR3_LUA);

			jassNativesInitialize();
			jassOpcodeInitialize();

			call(MakePtr(gameBase, _jassEntryPoint), jassEntryPoint);
		}
		else {
			return FALSE;
		}
	}

	return TRUE;
}