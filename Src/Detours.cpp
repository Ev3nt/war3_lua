#include "pch.h"
#include "Detours.h"
#include "Logger.h"

namespace Detour {
	BOOL Install(UINT_PTR* pointer_ptr, UINT_PTR detour) {
		BOOL error = NO_ERROR;

		if ((error = DetourTransactionBegin()) != NO_ERROR) { Logger::Log(Utils::format("DetourTransactionBegin failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }
		if (!error && (error = DetourUpdateThread(GetCurrentThread())) != NO_ERROR) { Logger::Log(Utils::format("DetourUpdateThread failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }
		if (!error && (error = DetourAttach((PVOID*)pointer_ptr, (PVOID)detour)) != NO_ERROR) { Logger::Log(Utils::format("DetourAttach failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }
		if (!error && (error = DetourTransactionCommit()) != NO_ERROR) { Logger::Log(Utils::format("DetourTransactionCommit failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }

		if (error != NO_ERROR) { DetourTransactionAbort(); }

		return error;
	}

	BOOL Uninstall(UINT_PTR* pointer_ptr, UINT_PTR detour) {
		BOOL error = NO_ERROR;

		if ((error = DetourTransactionBegin()) != NO_ERROR) { Logger::Log(Utils::format("DetourTransactionBegin failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }
		if (!error && (error = DetourUpdateThread(::GetCurrentThread())) != NO_ERROR) { Logger::Log(Utils::format("DetourUpdateThread failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }
		if (!error && (error = DetourDetach((PVOID*)pointer_ptr, (PVOID)detour)) != NO_ERROR) { Logger::Log(Utils::format("DetourAttach failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }
		if (!error && (error = DetourTransactionCommit()) != NO_ERROR) { Logger::Log(Utils::format("DetourTransactionCommit failed with error: %d.\n", error), Logger::LEVEL::LOG_ERROR); }

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