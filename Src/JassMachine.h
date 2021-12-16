#pragma once

#include <Windows.h>
#include <vector>

#include "Warcraft.h"

enum OPCODES {
	OPTYPE_MINLIMIT = 0x00,
	OPTYPE_ENDPROGRAM = 0x01,
	OPTYPE_OLDJUMP = 0x02,
	OPTYPE_FUNCTION = 0x03,
	OPTYPE_ENDFUNCTION = 0x04,
	OPTYPE_LOCAL = 0x05,
	OPTYPE_GLOBAL = 0x06,
	OPTYPE_CONSTANT = 0x07,
	OPTYPE_FUNCARG = 0x08,
	OPTYPE_EXTENDS = 0x09,
	OPTYPE_TYPE = 0x0A,
	OPTYPE_POPN = 0x0B,
	OPTYPE_MOVRLITERAL = 0x0C,
	OPTYPE_MOVRR = 0x0D,
	OPTYPE_MOVRV = 0x0E,
	OPTYPE_MOVRCODE = 0x0F,
	OPTYPE_MOVRA = 0x10,
	OPTYPE_MOVVR = 0x11,
	OPTYPE_MOVAR = 0x12,
	OPTYPE_PUSH = 0x13,
	OPTYPE_POP = 0x14,
	OPTYPE_CALLNATIVE = 0x15,
	OPTYPE_CALLJASS = 0x16,
	OPTYPE_I2R = 0x17,
	OPTYPE_AND = 0x18,
	OPTYPE_OR = 0x19,
	OPTYPE_EQUAL = 0x1A,
	OPTYPE_NOTEQUAL = 0x1B,
	OPTYPE_LESSEREQUAL = 0x1C,
	OPTYPE_GREATEREQUAL = 0x1D,
	OPTYPE_LESSER = 0x1E,
	OPTYPE_GREATER = 0x1F,
	OPTYPE_ADD = 0x20,
	OPTYPE_SUB = 0x21,
	OPTYPE_MUL = 0x22,
	OPTYPE_DIV = 0x23,
	OPTYPE_MOD = 0x24,
	OPTYPE_NEGATE = 0x25,
	OPTYPE_NOT = 0x26,
	OPTYPE_RETURN = 0x27,
	OPTYPE_LABEL = 0x28,
	OPTYPE_JUMPIFTRUE = 0x29,
	OPTYPE_JUMPIFFALSE = 0x2A,
	OPTYPE_JUMP = 0x2B,
	OPTYPE_MAXLIMIT = 0x2C,
	OPTYPE_STARTLUATHREAD = 0x2D
};

enum OPCODE_VARIABLE_TYPE {
	OPCODE_VARIABLE_NOTHING = 0,
	OPCODE_VARIABLE_UNKNOWN,
	OPCODE_VARIABLE_NULL,
	OPCODE_VARIABLE_CODE,
	OPCODE_VARIABLE_INTEGER,
	OPCODE_VARIABLE_REAL,
	OPCODE_VARIABLE_STRING,
	OPCODE_VARIABLE_HANDLE,
	OPCODE_VARIABLE_BOOLEAN,
	OPCODE_VARIABLE_INTEGER_ARRAY,
	OPCODE_VARIABLE_REAL_ARRAY,
	OPCODE_VARIABLE_STRING_ARRAY,
	OPCODE_VARIABLE_HANDLE_ARRAY,
	OPCODE_VARIABLE_BOOLEAN_ARRAY
};

#ifndef _JassMachine_h
#define _JassMachine_h
typedef struct {
	DWORD unk;
	DWORD zero1;
	DWORD zero2;
	DWORD zero3;
	DWORD zero4;
	DWORD zero5;
	DWORD type1;
	DWORD type2;
	DWORD value;
	DWORD zero6;

	void set(DWORD value, OPCODE_VARIABLE_TYPE type) {
		this->value = value;
		type1 = type;
		type2 = type;
	}

} JASS_DATA_SLOT, * PJASS_DATA_SLOT;

typedef struct {
private:
	DWORD unk1;
	DWORD unk2;
	size_t stack_top; // Idk why it's here
	PJASS_DATA_SLOT stack[32];
	size_t size;
public:
	PJASS_DATA_SLOT pop() {
		return stack[--size];
	}

	PJASS_DATA_SLOT& operator[](size_t index) {
		return stack[index];
	}

	void clear(size_t number) {
		size = number < size ? size - number : 0;
	}

	size_t Size() {
		return size;
	}
} JASS_STACK, * PJASS_STACK;

typedef struct {
private:
	std::vector<JASS_OPCODE> oplist;
public:
	void addop(BYTE opcode, BYTE reg = 0, DWORD value = NULL, BYTE type = OPCODE_VARIABLE_NOTHING, BYTE rettype = OPCODE_VARIABLE_NOTHING) {
		JASS_OPCODE* _opcode = new JASS_OPCODE;
		_opcode->rettype = rettype;
		_opcode->type = type;
		_opcode->reg = reg;
		_opcode->opcode = opcode;
		_opcode->value = value;

		oplist.push_back(*_opcode);
	}

	DWORD getcode() {
		return ((DWORD)&oplist - getJassMachine()->code_table->table) / 4;
	}

} JASS_OPLIST, * PJASS_OPLIST;
#endif

//---------------------------------------------------------

void jassOpcodeInitialize();