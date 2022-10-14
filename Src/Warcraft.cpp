#include "pch.h"
#include "Warcraft.h"
#include "Offsets.h"
#include "fp_call.h"

namespace Warcraft {
	VS_FIXEDFILEINFO* GetFileVersion(LPCSTR filename) {
		VS_FIXEDFILEINFO* version = NULL;
		DWORD handle;
		DWORD size = GetFileVersionInfoSize(filename, &handle);

		if (size) {
			LPSTR buffer = new char[size];

			if (GetFileVersionInfo(filename, handle, size, buffer) && buffer) {
				size = sizeof(VS_FIXEDFILEINFO);
				VerQueryValue(buffer, "\\", (LPVOID*)&version, (UINT*)&size);
				
			}

			delete[] buffer;
		}

		return version;
	}

	Version GetWarcraftVersion() {
		VS_FIXEDFILEINFO* version = GetFileVersion("game.dll");

		return version ? Version(version->dwFileVersionLS & 0xFFFF) : Version::NONE;
	}

	UINT GetGameUI(BOOL bInit, BOOL bRelease) {
		return pOffsets[(UINT)Offset::GetGameUI] ? fast_call<UINT>(pOffsets[(UINT)Offset::GetGameUI], bInit, bRelease) : NULL;
	}

	void PrintChat(LPCSTR text, float duration, DWORD color) {
		fast_call<void>(pOffsets[(UINT)Offset::DisplayTimedTextToPlayer], GetGameUI(0, 0), NULL, 0, 0, text, *(UINT*)&duration, color);
	}

	void PrintfChat(float duration, LPCSTR format, ...) {
		char text[8192] = { NULL };

		va_list args;
		va_start(args, format);
		vsprintf_s(text, format, args);
		va_end(args);

		PrintChat(text, duration);
	}

	HANDLE GetTLSValue() {
		return pOffsets[(UINT)Offset::GameTLSIndex] ? TlsGetValue(*(DWORD*)pOffsets[(UINT)Offset::GameTLSIndex]) : NULL;
	}

	DWORD GetTLSData(UINT_PTR pOffset) {
		return GetTLSValue() ? *(UINT_PTR*)((UINT_PTR)GetTLSValue() + pOffset) : NULL;
	}

	DWORD GetTLSValueByIndex(UINT index) {
		return GetTLSValue() ? ((DWORD*)GetTLSValue())[index] : NULL;
	}

	LPVOID ConvertHandle(UINT handle) {
		return handle > 0x100000 ? *(LPVOID*)(*(UINT*)(*(UINT*)(*(UINT*)pOffsets[(UINT)Offset::GameObject] + 0x1c) + 0x19c) + handle * 0xc - 0x2fffff * 4) : NULL;
	}
}