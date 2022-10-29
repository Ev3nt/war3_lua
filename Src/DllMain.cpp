#include "pch.h"
#include "JassMachine.h"
#include "JassNatives.h"
#include "Offsets.h"
#include "Hooks.h"
#include "Logger.h"
//#include "EasterEgg.h"

bool developerMode = false;
//SYSTEMTIME date;
//std::string celebratingText;

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

		JassMachine::JassOpcodeInitialize();

		Hooks::SetHooksState(true);

		break;
	case DLL_PROCESS_DETACH:
		Hooks::SetHooksState(false);

		Logger::CloseConsole();

		break;
	}

	return TRUE;
}

//---------------------------------------------------------------------

bool StartUp() {
	if (!InitOffsets()) {
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
		Logger::Log(Utils::format("%s\n%s (%s)\n", LUA_COPYRIGHT, WAR3_LUA, WAR3_LUA_VERSION_NAME));
	}

	return true;
}