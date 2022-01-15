#include <Windows.h>
#include <iostream>

#include "Variables.h"
#include "Mem.h"
#include "Hooks.h"
#include "JassMachine.h"

BOOL APIENTRY DllMain(HMODULE hModule, UINT ul_reason_for_call, LPVOID lpReserve)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		if (gameBase) {
			DisableThreadLibraryCalls(hModule);

			LPSTR cmdline = GetCommandLine();
			size_t i;
			for (i = strlen(cmdline); i > 0 && cmdline[i] != '\"'; i--);

			if (strstr(&cmdline[i + 1], "-console") || strstr(&cmdline[i + 1], "-debug")) {
				FILE* console;
				AllocConsole();
				freopen_s(&console, "CONOUT$", "w", stdout);
				SetConsoleTitle("Lua Console");
			}

			printf("%s\n%s\n", LUA_COPYRIGHT, WAR3_LUA);

			jassNativesInitialize();
			jassOpcodeInitialize();

			call(MakePtr(gameBase, _jassEntryPoint), jassEntryPoint);
			call(MakePtr(gameBase, _getWarcraftID1), getWarcraftID);
			call(MakePtr(gameBase, _getWarcraftID2), getWarcraftID);
			jmp(MakePtr(gameBase, 0x62a580), (DWORD)isFrameValid);
			jmp(MakePtr(gameBase, 0x629a90), (DWORD)frameEventObserver);

			break;
		}
		else {
			return FALSE;
		}
	case DLL_PROCESS_DETACH:
		BYTE originalFrameValid[] = { 0x8b, 0x49, 8, 0x33, 0xc0};
		patch(MakePtr(gameBase, 0x62a580), originalFrameValid,sizeof(originalFrameValid));

		BYTE originalFrameEventObserver[] = { 0x8b, 0x44, 0x24, 4, 0x8b };
		patch(MakePtr(gameBase, 0x629a90), originalFrameEventObserver, sizeof(originalFrameEventObserver));

		break;
	}

	return TRUE;
}