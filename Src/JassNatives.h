#pragma once

#include <Windows.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <lua.hpp>
#include "JassMachine.h"

enum JASS_TYPE : BYTE {
	TYPE_NONE = 0,
	TYPE_BOOLEAN = 'B',
	TYPE_CODE = 'C',
	TYPE_HANDLE = 'H',
	TYPE_INTEGER = 'I',
	TYPE_REAL = 'R',
	TYPE_STRING = 'S',
	TYPE_NOTHING = 'V',
};

inline UINT to_real(float value) {
	return *(UINT*)&value;
}

inline float from_real(UINT value) {
	return *(float*)&value;
}

inline UINT to_string(LPCSTR string) {
	UINT* pString = new UINT[8];

	pString[2] = (UINT)&pString[0];
	pString[7] = (UINT)&string[0];

	return (UINT)pString;
}

inline PCSTR from_string(UINT string) {
	if (!string) {
		return NULL;
	}

	string = ((UINT*)string)[2];

	if (!string) {
		return NULL;
	}

	return (PCSTR)((UINT*)string)[7];
}

UINT GetGroupByHandle(UINT handle);
UINT GetTriggerByHandle(UINT handle);
UINT GetTimerByHandle(UINT handle);

UINT to_code(lua_State* l, int index, UINT objectHandle);

inline DWORD to_ID(LPCSTR lpID) {
	return (lpID[0] << 24) + (lpID[1] << 16) + (lpID[2] << 8) + lpID[3];
}

//---------------------------------------------------------

#ifndef _JassNatives_h
#define _JassNatives_h
class JASSNATIVE {
public:
	JASSNATIVE(LPVOID address, LPCSTR params);
	JASSNATIVE();

	bool is_valid();
	const std::vector<JASS_TYPE>& get_params();
	const JASS_TYPE& get_rettype();
	PVOID get_address();

	BOOL call(LPVOID params, size_t size);
private:
	PVOID _address;
	std::vector<JASS_TYPE> _params;
	JASS_TYPE _rettype;
};
#endif

//---------------------------------------------------------

JASSNATIVE& get_native(LPCSTR name);

void jassNativesParse();

void JassNatives_reset();

//---------------------------------------------------------

extern std::unordered_map<LPCSTR, JASSNATIVE> jassnatives;