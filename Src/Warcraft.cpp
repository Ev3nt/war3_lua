#include "pch.h"
#include "Warcraft.h"
#include "fp_call.h"

auto GetInstanceTrue = (HANDLE(__fastcall*)(UINT))((std::ptrdiff_t)gameBase + 0x4c34d0);
UINT pGameState = (std::ptrdiff_t)gameBase + 0xab65f4;
UINT pGameClass2 = (std::ptrdiff_t)gameBase + 0xab4f80;

void PrintChat(LPCSTR text, float duration) {
	fast_call<void>((std::ptrdiff_t)gameBase + 0x2f8e40, *(UINT*)pGameClass2, NULL, 0, 0, text, *(UINT*)&duration, 0xFFFFFFFF);
	//((void(__fastcall*)(UINT, UINT, UINT, UINT, LPCSTR, UINT, UINT))((UINT)gameBase + 0x2f8e40))(*(UINT*)pGameClass2, NULL, 0, 0, text, *(UINT*)&duration, 0xFFFFFFFF);
}

void PrintfChat(float duration, LPCSTR format, ...) {
	char text[8192] = { NULL };

	va_list args;
	va_start(args, format);
	vsprintf_s(text, format, args);
	va_end(args);

	PrintChat(text, duration);
}

HANDLE GetInstance(UINT index) {
	return GetInstanceTrue(index);
}

LPVOID ConvertHandle(UINT handle) {
	return handle ? *(LPVOID*)(*(UINT*)(*(UINT*)(*(UINT*)pGameState + 0x1c) + 0x19c) + handle * 0xc - 0x2fffff * 4) : NULL;
}