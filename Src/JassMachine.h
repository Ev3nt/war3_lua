#pragma once

#include "Warcraft.h"
#include "JassNatives.h"

enum class OPCODE_TYPE : BYTE {
	ENDPROGRAM = 1,
	OLDJUMP,
	FUNCTION,
	ENDFUNCTION,
	LOCAL,
	GLOBAL,
	CONSTANT,
	FUNCARG,
	EXTENDS,
	TYPE,
	POPN,
	MOVRLITERAL,
	MOVRR,
	MOVRV,
	MOVRCODE,
	MOVRA,
	MOVVR,
	MOVAR,
	PUSH,
	POP,
	CALLNATIVE,
	CALLJASS,
	I2R,
	AND,
	OR,
	EQUAL,
	NOTEQUAL,
	LESSEREQUAL,
	GREATEREQUAL,
	LESSER,
	GREATER,
	ADD,
	SUB,
	MUL,
	DIV,
	MOD,
	NEGATE,
	NOT,
	RETURN,
	LABE,
	JUMPIFTRUE,
	JUMPIFFALSE,
	JUMP,
	STARTLUATHREAD
};

enum class OPCODE_VARIABLE : BYTE {
	TYPE_NOTHING = 0,
	TYPE_UNKNOWN,
	TYPE_NULL,
	TYPE_CODE,
	TYPE_INTEGER,
	TYPE_REAL,
	TYPE_STRING,
	TYPE_HANDLE,
	TYPE_BOOLEAN,
	TYPE_INTEGER_ARRAY,
	TYPE_REAL_ARRAY,
	TYPE_STRING_ARRAY,
	TYPE_HANDLE_ARRAY,
	TYPE_BOOLEAN_ARRAY
};

namespace JassMachine {
	typedef struct {
		DWORD unk;
		DWORD zero1;
		DWORD zero2;
		DWORD zero3;
		DWORD zero4;
		DWORD zero5;
		DWORD type1; // OPCODE_VARIABLE
		DWORD type2; // OPCODE_VARIABLE
		DWORD value;
		DWORD zero6;

		void Set(DWORD value, OPCODE_VARIABLE type) {
			this->value = value;
			type1 = (DWORD)type;
			type2 = (DWORD)type;
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
		UINT refCount;    // 0x4
		UINT hash;        // 0x8
		PVOID table;        // 0xC
		CStringRep* prev;        // 0x10
		/* txtnode */
		PVOID prevtxtnode; // 0x14  ?
		CStringRep* next;         // 0x18
		char* text;         // 0x1C
	} * PCStringRep;//sizeof = 0x20

	typedef struct {
		uintptr_t vtable;        // 0x0 PVOID*
		UINT unk1;        // 0x4
		PCStringRep stringRep;    // 0x8
		UINT unk2;
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
		OPCODE_VARIABLE returntype;
		OPCODE_VARIABLE type;
		BYTE reg;
		OPCODE_TYPE opcode;
		DWORD value;
	} JASS_OPCODE, * PJASS_OPCODE;

	typedef struct {
		UINT max;
		UINT min;
		UINT* value;
	} JASS_DATA_LIST, * PJASS_DATA_LIST;

	typedef struct {
		uintptr_t* vtable;            // 0x0
		JASS_DATA_LIST list;            // 0x4 - 0xC
	} JASS_ARRAY, * PJASS_ARRAY;

	typedef struct JASS_VARIABLE {
		UINT				hashKey;		// 0x0
		PVOID unk_04;			// 0x4
		PVOID unk_08;			// 0x8
		PVOID prev;			// 0xC
		JASS_VARIABLE* next;			// 0x10
		LPCSTR name;			// 0x14
		UINT				recType;		// 0x18
		UINT				retType;		// 0x1C
		UINT				value;			// 0x20
	} * PJASS_VARIABLE;

	typedef struct {
		uintptr_t* vtable;                            // 0x00
		UINT        comCount;                        // 0x04
		PJASS_VARIABLE variableReversed;                // 0x08
		PJASS_VARIABLE variable;                        // 0x0C
		UINT        unk_10;                            // 0x10
		UINT        customVariables[3];                // 0x14 - 0x20
		UINT        unk_24;                            // 0x24
	} SCRIPT_DATA_TABLE, * PSCRIPT_DATA_TABLE;

	typedef struct {
		BYTE unk0[0x20]; // 0x00
		PJASS_OPCODE opcode; // 0x20
		BYTE unk1[0x10]; // 0x24
		UINT has_sleep; // 0x34
		BYTE unk2[0x18]; // 0x38
		JASS_DATA_SLOT condition_return_value; // 0x50
		BYTE unk3[0x27D8]; // 0x54
		size_t index; // 0x2850
		BYTE unk4[0x8]; // 0x2854
		PSCRIPT_DATA_TABLE script_table;
		BYTE unk5[0x8];
		PJASS_STACK stack; // 0x2868
		BYTE unk6[0x8];
		PSTRING_TABLE string_table; // 0x2874
		BYTE unk7[0x10];
		PCODE_TABLE code_table;
		BYTE unk8[0x1C];
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
		OPCODE_VARIABLE returnType; // 0x38
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
		void AddOperation(OPCODE_TYPE opcode, BYTE reg = 0, DWORD value = NULL, OPCODE_VARIABLE type = OPCODE_VARIABLE::TYPE_NOTHING, OPCODE_VARIABLE returntype = OPCODE_VARIABLE::TYPE_NOTHING) {
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

	PJASS_VARIABLE GetVariableDataNodeByName(PSCRIPT_DATA_TABLE pDataNode, const std::string& name);

	PJASS_VARIABLE GetVariableDataNodeByNameEx(PJASS_INSTANCE jvm, const std::string& name);
}