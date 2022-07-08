#pragma once

#include "Warcraft.h"
#include "JassNatives.h"

namespace JassMachine {
	enum OPCODES : BYTE {
		OPTYPE_ENDPROGRAM = 1,
		OPTYPE_OLDJUMP,
		OPTYPE_FUNCTION,
		OPTYPE_ENDFUNCTION,
		OPTYPE_LOCAL,
		OPTYPE_GLOBAL,
		OPTYPE_CONSTANT,
		OPTYPE_FUNCARG,
		OPTYPE_EXTENDS,
		OPTYPE_TYPE,
		OPTYPE_POPN,
		OPTYPE_MOVRLITERAL,
		OPTYPE_MOVRR,
		OPTYPE_MOVRV,
		OPTYPE_MOVRCODE,
		OPTYPE_MOVRA,
		OPTYPE_MOVVR,
		OPTYPE_MOVAR,
		OPTYPE_PUSH,
		OPTYPE_POP,
		OPTYPE_CALLNATIVE,
		OPTYPE_CALLJASS,
		OPTYPE_I2R,
		OPTYPE_AND,
		OPTYPE_OR,
		OPTYPE_EQUAL,
		OPTYPE_NOTEQUAL,
		OPTYPE_LESSEREQUAL,
		OPTYPE_GREATEREQUAL,
		OPTYPE_LESSER,
		OPTYPE_GREATER,
		OPTYPE_ADD,
		OPTYPE_SUB,
		OPTYPE_MUL,
		OPTYPE_DIV,
		OPTYPE_MOD,
		OPTYPE_NEGATE,
		OPTYPE_NOT,
		OPTYPE_RETURN,
		OPTYPE_LABE,
		OPTYPE_JUMPIFTRUE,
		OPTYPE_JUMPIFFALSE,
		OPTYPE_JUMP,
		OPTYPE_STARTLUATHREAD
	};

	enum OPCODE_VARIABLE_TYPE : BYTE {
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

		void Set(DWORD value, OPCODE_VARIABLE_TYPE type) {
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
		PJASS_DATA_SLOT Pop() {
			return stack[--size];
		}

		PJASS_DATA_SLOT& operator[](size_t index) {
			return stack[index];
		}

		void Clear(size_t number) {
			size = number < size ? size - number : 0;
		}

		size_t Size() {
			return size;
		}
	} JASS_STACK, * PJASS_STACK;

	typedef struct CStringRep {
		uintptr_t vtable;        // 0x0
		uint32_t refCount;    // 0x4
		uint32_t hash;        // 0x8
		PVOID table;        // 0xC
		CStringRep* prev;        // 0x10
		/* txtnode */
		void* prevtxtnode; // 0x14  ?
		CStringRep* next;         // 0x18
		char* text;         // 0x1C
	} * PCStringRep;//sizeof = 0x20

	typedef struct {
		uintptr_t vtable;        // 0x0 void**
		uint32_t unk1;        // 0x4
		PCStringRep stringRep;    // 0x8
		uint32_t unk2;
	} RCString, * PRCString;

	typedef struct {
		DWORD unk;
		size_t size;
		PRCString strings;

		/*DWORD Get(UINT index) {
			DWORD result = 0;

			if (index < size) {
				result = (DWORD)strings + 0x10 * index;
				++* (DWORD*)(result + 0xC);
			}

			return result;
		}*/
		RCString& GetRCString(size_t index) {
			return strings[index];
		}

		CStringRep& GetCStringRep(size_t index) {
			return *(strings[index].stringRep);
		}

		LPCSTR GetString(size_t index, bool countRef = true) {
			if (countRef) {
				strings[index].stringRep->refCount++;
			}

			return strings[index].stringRep->text;
		}

	} STRING_TABLE, * PSTRING_TABLE;

	typedef struct {
		BYTE unk[4];
		size_t counter;
		DWORD* codes; // max_size = 1024

		size_t PushCode(DWORD address) {
			codes[counter] = address;

			return counter++;
		}

		size_t Size() {
			return counter;
		}
	} CODE_TABLE, * PCODE_TABLE;

	typedef struct {
		BYTE returntype;
		BYTE type;
		BYTE reg;
		BYTE opcode;
		DWORD value;
	} JASS_OPCODE, * PJASS_OPCODE;

	typedef struct {
		BYTE unk0[0x20]; // 0x00
		PJASS_OPCODE opcode; // 0x20
		BYTE unk1[0x10]; // 0x24
		UINT has_sleep; // 0x34
		BYTE unk2[0x18]; // 0x38
		JASS_DATA_SLOT condition_return_value; // 0x50
		BYTE unk3[0x27D8]; // 0x54
		size_t index; // 0x2850
		BYTE unk4[0x14]; // 0x2854
		PJASS_STACK stack; // 0x2868
		BYTE unk5[0x8];
		PSTRING_TABLE string_table; // 0x2874
		BYTE unk6[0x10];
		PCODE_TABLE code_table;
		BYTE unk7[0x1C];
	} JASS_INSTANCE, * PJASS_INSTANCE;

#pragma pack(push)
#pragma pack(4)
	struct JASS_NATIVE {
		uintptr_t vTable; // 0x0
		uintptr_t unk1; // 0x04
		uintptr_t unk2;	// 0x08
		uintptr_t unk3;	// 0x0c
		uintptr_t unk4;	// 0x10
		JASS_NATIVE* next; // 0x14
		LPCSTR name; // 0x18
		LPVOID callback; // 0x1c
		size_t argCount; // 0x20
		LPCSTR arguments; // 0x24
		size_t maxArgs; // 0x28
		size_t minArgs; // 0x2c
		uintptr_t unk5; // 0x30
		uintptr_t unk6; // 0x34
		OPCODE_VARIABLE_TYPE returnType; // 0x38
	};
#pragma pack(pop)

	typedef struct {
		uintptr_t vTable; // 0x00
		uintptr_t unk1; // 0x04
		uintptr_t unk2; // 0x08
		uintptr_t unk3; // 0x0c
		uintptr_t unk4; // 0x10
		uintptr_t unk5; // 0x14
		uintptr_t unk6; // 0x18
		uintptr_t unk7; // 0x1c
		JASS_NATIVE* lastNative; // 0x20
		JASS_NATIVE* firstNative; // 0x24
	} JASS_THREAD_LOCAL, * PJASS_THREAD_LOCAL;

	PJASS_THREAD_LOCAL GetJassThreadLocal();

	PJASS_INSTANCE GetJassMachine(UINT index = 1);

	PJASS_INSTANCE GetJassInstance();

	typedef struct {
	private:
		std::vector<JASS_OPCODE> oplist;
	public:
		void AddOperation(OPCODES opcode, BYTE reg = 0, DWORD value = NULL, OPCODE_VARIABLE_TYPE type = OPCODE_VARIABLE_NOTHING, OPCODE_VARIABLE_TYPE returntype = OPCODE_VARIABLE_NOTHING) {
			JASS_OPCODE* _opcode = new JASS_OPCODE;
			_opcode->returntype = returntype;
			_opcode->type = type;
			_opcode->reg = reg;
			_opcode->opcode = opcode;
			_opcode->value = value;

			oplist.push_back(*_opcode);
		}

		DWORD GetCode() {
			return ((DWORD)&oplist - (DWORD)GetJassMachine()->code_table->codes) / sizeof(DWORD);
		}

	} JASS_OPLIST, * PJASS_OPLIST;

	//---------------------------------------------------------

	void JassOpcodeInitialize();
}