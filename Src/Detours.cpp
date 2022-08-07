#include "pch.h"
#include "Detours.h"

namespace Detour {
	BOOL Install(UINT_PTR* pointer_ptr, UINT_PTR detour) {
		BOOL error = NO_ERROR;

		if ((error = DetourTransactionBegin()) != NO_ERROR) { printf("DetourTransactionBegin failed with error: %d.\n", error); }
		if (!error && (error = DetourUpdateThread(GetCurrentThread())) != NO_ERROR) { printf("DetourUpdateThread failed with error: %d.\n", error); }
		if (!error && (error = DetourAttach((PVOID*)pointer_ptr, (PVOID)detour)) != NO_ERROR) { printf("DetourAttach failed with error: %d.\n", error); }
		if (!error && (error = DetourTransactionCommit()) != NO_ERROR) { printf("DetourTransactionCommit failed with error: %d.\n", error); }

		if (error != NO_ERROR) { DetourTransactionAbort(); }

		return error;
	}

	BOOL Uninstall(UINT_PTR* pointer_ptr, UINT_PTR detour) {
		BOOL error = NO_ERROR;

		if ((error = DetourTransactionBegin()) != NO_ERROR) { wprintf_s(L"DetourTransactionBegin failed with error: %d.\n", error); }
		if (!error && (error = DetourUpdateThread(::GetCurrentThread())) != NO_ERROR) { wprintf_s(L"DetourUpdateThread failed with error: %d.\n", error); }
		if (!error && (error = DetourDetach((PVOID*)pointer_ptr, (PVOID)detour)) != NO_ERROR) { wprintf_s(L"DetourAttach failed with error: %d.\n", error); }
		if (!error && (error = DetourTransactionCommit()) != NO_ERROR) { wprintf_s(L"DetourTransactionCommit failed with error: %d.\n", error); }

		if (error != NO_ERROR) { DetourTransactionAbort(); }

		return error;
	}

	BOOL InstallEx(bool flag, UINT_PTR* pointer_ptr, UINT_PTR detour) {
		if (pointer_ptr && *pointer_ptr != NULL) {
			return flag ? Install(pointer_ptr, detour) : Uninstall(pointer_ptr, detour);
		}

		return -1;
	}

	BOOL SetState(bool flag, UINT_PTR* pointer_ptr, UINT_PTR detour) {
		return flag ? Install(pointer_ptr, detour) : Uninstall(pointer_ptr, detour);
	}
}