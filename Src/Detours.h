#pragma once

namespace Detour {
	BOOL Install(UINT_PTR* pointer_ptr, UINT_PTR detour);
	BOOL Uninstall(UINT_PTR* pointer_ptr, UINT_PTR detour);
	BOOL InstallEx(bool flag, UINT_PTR* pointer_ptr, UINT_PTR detour);
	BOOL SetState(bool flag, UINT_PTR* pointer_ptr, UINT_PTR detour);
}