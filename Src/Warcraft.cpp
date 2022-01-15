#include "Warcraft.h"
#include "Global.h"

auto getInstanceTrue = (HANDLE(__fastcall*)(UINT))((UINT_PTR)gameBase + 0x4c34d0);

PJASS_INSTANCE getJassMachine(UINT index) {
	UINT_PTR jass_thread = *(UINT_PTR*)(*(UINT_PTR*)((UINT_PTR)getInstance(5) + 0x90) + index * 4);

	return jass_thread ? (PJASS_INSTANCE)jass_thread : NULL;
}

PJASS_INSTANCE getJassInstance() {
	HANDLE instance = getInstance(5);

	return *(UINT_PTR*)((UINT_PTR)instance + 0x14) ? *(PJASS_INSTANCE*)(*(UINT_PTR*)((UINT_PTR)instance + 0xc) + *(UINT_PTR*)((UINT_PTR)instance + 0x14) * 4 - 4) : NULL;
}

HANDLE getInstance(UINT index) {
	return getInstanceTrue(index);
}