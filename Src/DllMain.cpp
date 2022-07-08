#include "pch.h"
#include "JassMachine.h"
#include "JassNatives.h"
#include "Hooks.h"
#include "Logger.h"
#include "EasterEgg.h"

bool developerMode = false;
SYSTEMTIME date;
std::string celebratingText;

bool StartUp();

//---------------------------------------------------------------------

BOOL APIENTRY DllMain(HMODULE module, UINT reason, LPVOID reserved) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		if (!gameBase) {
			return FALSE;
		}

		if (!StartUp()) {
			return FALSE;
		}

		GetLocalTime(&date);
		celebratingText = GetEasterText(date);
		!celebratingText.empty() ? MessageBox(NULL, celebratingText.c_str(), "Celebration Message!", MB_ICONINFORMATION) : NULL;

		JassMachine::JassOpcodeInitialize();

		Hooks::AttachHooks();

		break;
	case DLL_PROCESS_DETACH:

		Hooks::DetachHooks();

		Logger::CloseConsole();

		break;
	}

	return TRUE;
}

//---------------------------------------------------------------------

bool StartUp() {
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
		Logger::OpenConsole(developerMode ? "Lua Console [Developer]" : "Lua Console");

		system("cls");
		printf("%s\n%s (%s)\n\n", LUA_COPYRIGHT, WAR3_LUA, WAR3_LUA_VERSION_NAME);
	}

	return true;
}