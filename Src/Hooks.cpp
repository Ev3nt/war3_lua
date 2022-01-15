#include "Hooks.h"
#include "LuaMachine.h"
#include "GameUI.h"
#include "Global.h"
#include <detours.h>

auto jassEntryPointTrue = (BOOL(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x3b54b0);
auto getWarcraftIDTrue = (DWORD(__stdcall*)())((UINT_PTR)gameBase + 0x537ed0);
auto isFrameHasEventObserverTrue = (BOOL(__fastcall*)(UINT, UINT, UINT, UINT))((UINT_PTR)gameBase + 0x62a580);
auto frameEventCallbackTrue = (BOOL(__fastcall*)(UINT, UINT, DWORD))((UINT_PTR)gameBase + 0x629a90);
auto CreateMatrixPerspectiveFovTrue = (void(__fastcall*)(UINT, UINT, float, float, float, float))((UINT_PTR)gameBase + 0x7b66f0);
auto BuildHPBarsTrue = (void(__fastcall*)(UINT, UINT, UINT, UINT))((UINT_PTR)gameBase + 0x379a30);

BOOL __fastcall jassEntryPoint(UINT unknown1) {
	return jassEntryPointTrue(unknown1) && startLua();
}

DWORD __stdcall getWarcraftID()
{
    return *(DWORD*)GAME_ID;
}

BOOL __fastcall isFrameHasEventObserver(UINT frame, UINT, UINT eventcode) {
	if (frameEventHashTable.find(frame) != frameEventHashTable.end()) {
		return TRUE;
	}

	UINT table = *(DWORD*)(frame + 8);

	if (!table) {
		return FALSE;
	}

	return reinterpret_cast<BOOL(__fastcall*)(UINT, UINT, UINT, UINT)>((UINT_PTR)gameBase + 0x62a1c0)(table, NULL, eventcode, 0);
}

BOOL __fastcall frameEventCallback(UINT frame, UINT, DWORD eventaddress) {
	UINT eventtype = *(UINT*)(eventaddress + 8);
	BOOL result = -1;

	if (running) {
		result = eventCallback(frame, eventtype, eventaddress);
	}

	return result == -1 ? reinterpret_cast<BOOL(__fastcall*)(UINT, UINT, UINT, DWORD)>(*(DWORD*)(*(DWORD*)frame + 0x14))(frame, NULL, eventtype, eventaddress) : result;
}

float wideScreenMul = 1.0f;
void __fastcall CreateMatrixPerspectiveFov(UINT outMatrix, UINT unused, float fovY, float aspectRatio, float nearZ, float farZ) {
	RECT rect;
	if (gameWindow && GetWindowRect(gameWindow, &rect)) {
		float width = float(rect.right - rect.left);
		float height = 1.0f / (rect.bottom - rect.top);
		wideScreenMul = width * height * 0.75f;
	}

	float yScale = 1.0f / tan(fovY * 0.5f / sqrt(aspectRatio * aspectRatio + 1.0f));
	float xScale = yScale / (aspectRatio * wideScreenMul);

	*(float*)(outMatrix) = xScale;
	*(float*)(outMatrix + 16) = 0.0f;
	*(float*)(outMatrix + 32) = 0.0f;
	*(float*)(outMatrix + 48) = 0.0f;

	*(float*)(outMatrix + 4) = 0.0f;
	*(float*)(outMatrix + 20) = yScale;
	*(float*)(outMatrix + 36) = 0.0f;
	*(float*)(outMatrix + 52) = 0.0f;

	*(float*)(outMatrix + 8) = 0.0f;
	*(float*)(outMatrix + 24) = 0.0f;
	*(float*)(outMatrix + 40) = (nearZ + farZ) / (farZ - nearZ);
	*(float*)(outMatrix + 56) = (-2.0f * nearZ * farZ) / (farZ - nearZ);

	*(float*)(outMatrix + 12) = 0.0f;
	*(float*)(outMatrix + 28) = 0.0f;
	*(float*)(outMatrix + 44) = 1.0f;
	*(float*)(outMatrix + 60) = 0.0f;
}

void __fastcall BuildHPBars(UINT a1, UINT unused, UINT a2, UINT a3) {
	BuildHPBarsTrue(a1, unused, a2, a3);

	UINT_PTR pHPBarFrame = *((UINT_PTR*)a1 + 3);
	if (pHPBarFrame) {
		*((float*)pHPBarFrame + 22) /= wideScreenMul;
	}
}

//----------------------------------------------------------------

void attachHooks() {
    DetourTransactionBegin();

    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)jassEntryPointTrue, jassEntryPoint);

    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)getWarcraftIDTrue, getWarcraftID);

	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)isFrameHasEventObserverTrue, isFrameHasEventObserver);

	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)frameEventCallbackTrue, frameEventCallback);

	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)CreateMatrixPerspectiveFovTrue, CreateMatrixPerspectiveFov);

	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)BuildHPBarsTrue, BuildHPBars);

    DetourTransactionCommit();
}

void detachHooks() {
    DetourTransactionBegin();

    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)jassEntryPointTrue, jassEntryPoint);

    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)getWarcraftIDTrue, getWarcraftID);

	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)isFrameHasEventObserverTrue, isFrameHasEventObserver);

	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)frameEventCallbackTrue, frameEventCallback);

	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)CreateMatrixPerspectiveFovTrue, CreateMatrixPerspectiveFov);

	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)BuildHPBarsTrue, BuildHPBars);

    DetourTransactionCommit();
}