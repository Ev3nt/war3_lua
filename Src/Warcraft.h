#pragma once

#include <Windows.h>

#ifndef _Warcraft_h
#define _Warcraft_h
typedef struct {
	DWORD unk;
	size_t max_size;
	UINT_PTR array;

	DWORD get(UINT index) {
		DWORD result = 0;

		if (index < max_size) {
			result = array + 0x10 * index;
			++*(DWORD*)(result + 0xC);
		}

		return result;
	}

} STRING_TABLE, * PSTRING_TABLE;

typedef struct {
	BYTE unk[4];
	size_t counter;
	DWORD* codes; // max_size = 1024

	size_t push_code(DWORD address) {
		codes[counter] = address;

		return counter++;
	}

	size_t size() {
		return counter;
	}
} CODE_TABLE, * PCODE_TABLE;

typedef struct {
	BYTE rettype;
	BYTE type;
	BYTE reg;
	BYTE opcode;
	DWORD value;
} JASS_OPCODE, * PJASS_OPCODE;

typedef struct {
	BYTE unk0[0x20];
	PJASS_OPCODE opcode;
	BYTE unk1[0x10];
	UINT has_sleep;
	BYTE unk2[0x2818];
	size_t index;
	BYTE unk3[0x20];
	PSTRING_TABLE string_table;
	BYTE unk4[0x10];
	PCODE_TABLE code_table;
	BYTE unk5[0x1C];
} JASS_INSTANCE, * PJASS_INSTANCE;
#endif

PJASS_INSTANCE getJassMachine(UINT index = 1);

PJASS_INSTANCE getJassInstance();

HANDLE getInstance(UINT index);