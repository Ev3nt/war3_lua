#include <Windows.h>
#include <iostream>
#include <detours.h>
#include "Global.h"
#include "lua.h"
#include "JassNatives.h"
#include "JassMachine.h"
#include "Hooks.h"
#include "Utils.h"

bool consoleMode = false;
bool developerMode = false;

bool startUp();

//-----------------------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE module, UINT reason, LPVOID reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		if (!gameBase) {
			return FALSE;
		}
		
		DisableThreadLibraryCalls(module);

		if (!startUp()) {
			return FALSE;
		}

		if (consoleMode) {
			system("cls");
		}
		printf("%s\n%s (%s)\n", LUA_COPYRIGHT, WAR3_LUA, WAR3_LUA_VERSION_NAME);

		jassNativesParse();
		jassOpcodeInitialize();

		attachHooks();

		break;
	case DLL_PROCESS_DETACH:
		detachHooks();

		break;
	}

	return TRUE;
}

//-----------------------------------------------------------------------------

bool startUp() {
	DWORD handle;
	DWORD size = GetFileVersionInfoSize("game.dll", &handle);

	LPSTR buffer = new char[size];
	GetFileVersionInfo("game.dll", handle, size, buffer);

	VS_FIXEDFILEINFO* verInfo;
	size = sizeof(VS_FIXEDFILEINFO);
	VerQueryValue(buffer, "\\", (LPVOID*)&verInfo, (UINT*)&size);
	delete[] buffer;

	if (((verInfo->dwFileVersionMS >> 16) & 0xffff) != 1 || ((verInfo->dwFileVersionMS >> 0) & 0xffff) != 26 || ((verInfo->dwFileVersionLS >> 16) & 0xffff) != 0 || ((verInfo->dwFileVersionLS >> 0) & 0xffff) != 6401)
	{
		MessageBox(NULL, "Unsupported version of game.dll.\nLua will be unloaded.", "Error", MB_ICONHAND | MB_TOPMOST);

		return false;
	}

	PSTR cmdline = GetCommandLine();
	size_t i;
	for (i = strlen(cmdline); i > 0 && cmdline[i] != '\"'; i--);

	if (strstr(&cmdline[i + 1], "-dev")) {
		developerMode = true;
	}

	if (strstr(&cmdline[i + 1], "-console") || strstr(&cmdline[i + 1], "-debug")) {
		consoleMode = openConsole(developerMode ? "Lua Console [Developer]" : "Lua Console") ? true : false;
	}

	return true;
}