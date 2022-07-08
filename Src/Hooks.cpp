#include "pch.h"
#include "Hooks.h"
#include "LuaMachine.h"

#define AttachDetour(pointer, detour) (DetourUpdateThread(GetCurrentThread()), DetourAttach(&(PVOID&)pointer, detour))
#define DetachDetour(pointer, detour) (DetourUpdateThread(GetCurrentThread()), DetourDetach(&(PVOID&)pointer, detour))

namespace Hooks {
	auto SetJassState = (void(__fastcall*)(BOOL jassState))((std::ptrdiff_t)gameBase + 0x2ab0e0);
	auto GetWarcraftID = (DWORD(__stdcall*)())((std::ptrdiff_t)gameBase + 0x537ed0);

	DWORD GetWarcraftIDCustom()
	{
		return *(DWORD*)GAME_ID;
	}

	void __fastcall SetJassStateCustom(BOOL jassState) {
		if (jassState == TRUE) {
			LuaMachine::StartLua();
		}

		return SetJassState(jassState);
	}

	void AttachHooks() {
		DetourTransactionBegin();

		AttachDetour(SetJassState, SetJassStateCustom);
		AttachDetour(GetWarcraftID, GetWarcraftIDCustom);

		DetourTransactionCommit();
	}

	void DetachHooks() {
		DetourTransactionBegin();

		DetachDetour(SetJassState, SetJassStateCustom);
		DetachDetour(GetWarcraftID, GetWarcraftIDCustom);

		DetourTransactionCommit();
	}
}