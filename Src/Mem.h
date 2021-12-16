#pragma once

#include <Windows.h>

#define MakePtr(a, b) ((DWORD)a + (DWORD)b)

inline bool patch(LPVOID lpAddress, LPVOID lpData, SIZE_T dwSize) {
	DWORD dwOldProtect;

	if (VirtualProtect(lpAddress, dwSize, PAGE_EXECUTE_READWRITE, &dwOldProtect)) {
		memcpy(lpAddress, lpData, dwSize);

		VirtualProtect(lpAddress, dwSize, dwOldProtect, NULL);

		return true;
	}

	return false;
}

inline bool patch(DWORD dwAddress, LPVOID lpData, SIZE_T dwSize) {
	return patch((LPVOID)dwAddress, lpData, dwSize);
}

inline bool call(LPVOID lpAddress, LPVOID lpProc) {
	DWORD dwOldProtect;

	if (VirtualProtect(lpAddress, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect)) {
		*(CHAR*)lpAddress = (BYTE)0xE8;
		*(DWORD*)((DWORD)lpAddress + 1) = (DWORD)lpProc - ((DWORD)lpAddress + 5);

		VirtualProtect(lpAddress, 5, dwOldProtect, NULL);

		return true;
	}

	return false;
}

inline bool call(DWORD dwAddress, LPVOID lpProc) {
	return call((LPVOID)dwAddress, lpProc);
}

inline bool jmp(LPVOID lpAddress, LPVOID lpDestination) {
	DWORD dwOldProtect;

	if (VirtualProtect(lpAddress, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect)) {
		*(CHAR*)lpAddress = (BYTE)0xE9;
		*(DWORD*)((DWORD)lpAddress + 1) = (DWORD)lpDestination - ((DWORD)lpAddress + 5);

		VirtualProtect(lpAddress, 5, dwOldProtect, NULL);

		return true;
	}

	return false;
}

inline bool jmp(DWORD dwAddress, DWORD lpDestination) {
	return jmp((LPVOID)dwAddress, (LPVOID)lpDestination);
}