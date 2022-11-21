#pragma once

#include "Offsets.h"

//enum JASS_TYPE : BYTE {
//	TYPE_NONE = 0,
//	TYPE_BOOLEAN = 'B',
//	TYPE_CODE = 'C',
//	TYPE_HANDLE = 'H',
//	TYPE_INTEGER = 'I',
//	TYPE_REAL = 'R',
//	TYPE_STRING = 'S',
//	TYPE_NOTHING = 'V',
//};

namespace Jass {
	inline UINT ToReal(float value) {
		return *(UINT*)&value;
	}

	inline float FromReal(UINT value) {
		return *(float*)&value;
	}

	inline UINT ToString(LPCSTR string) {
		return this_call<UINT>(pOffsets[(UINT)Offset::jStringToString], string);
		//return std_call<UINT>((std::ptrdiff_t)gameBase + 0x454930, string, 0);
		/*
		UINT* pString = new UINT[8];

		pString[2] = (UINT)&pString[0];
		pString[7] = (UINT)&string[0];

		return (UINT)pString;*/
	}

	inline PCSTR FromString(UINT string) {
		if (!string) {
			return NULL;
		}

		string = ((UINT*)string)[2];

		if (!string) {
			return NULL;
		}

		return (PCSTR)((UINT*)string)[7];
	}

	UINT ToCode(lua_State* l, int index, int keyIndex);

	inline DWORD ToID(LPCSTR lpID) {
		return (lpID[0] << 24) + (lpID[1] << 16) + (lpID[2] << 8) + lpID[3];
	}

	//---------------------------------------------------------

	class JASSNATIVE {
	public:
		JASSNATIVE(LPVOID address, std::string params);
		JASSNATIVE();

		bool IsValid();
		const std::vector<std::string>& GetParams();
		const std::string& GetReturnType();
		PVOID GetAddress();
		const size_t GetRealsCount();

		DWORD Invoke(LPVOID params, size_t size);
	private:
		size_t m_realsCount;
		PVOID m_address;
		std::vector<std::string> m_params;
		std::string m_returntype;
	};

	//---------------------------------------------------------

	JASSNATIVE& GetNative(std::string name);

	void JassNativesParse();
	void JassNativesReset();

	//---------------------------------------------------------

	extern std::unordered_map<std::string, JASSNATIVE> jassnatives;
}