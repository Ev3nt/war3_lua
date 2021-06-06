#pragma once

#include <Windows.h>

typedef struct
{
	DWORD unk;
	DWORD max_size;
	DWORD array;

	UINT32 get(DWORD index)
	{
		DWORD result = 0;
		if (index < max_size)
		{
			result = array + 0x10 * index;
			++* (UINT32*)(result + 0xC);
		}

		return result;
	}

} STRING_TABLE, * PSTRING_TABLE;

typedef struct {
	BYTE unk[8];
	DWORD table;
} CODE_TABLE, * PCODE_TABLE;

typedef struct {
	BYTE rettype;
	BYTE type;
	BYTE reg;
	BYTE opcode;
	DWORD value;
} JASS_OPCODE, * PJASS_OPCODE;

typedef struct
{
	BYTE unk0[0x20];
	PJASS_OPCODE opcode;
	BYTE unk1[0x10];
	UINT has_sleep;
	BYTE unk2[0x2818];
	DWORD index;
	BYTE unk3[0x20];
	PSTRING_TABLE string_table;
	BYTE unk4[0x10];
	PCODE_TABLE code_table;
	BYTE unk5[0x1C];
} JASS_INSTANCE, * PJASS_INSTANCE;

PJASS_INSTANCE GetJassMachine(DWORD index = 1);

PJASS_INSTANCE GetJassInstance();

DWORD GetInstance(DWORD index);