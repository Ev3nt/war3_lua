#include "pch.h"
#include "JassMachine.h"
#include "LuaMachine.h"
#include "fp_call.h"

namespace JassMachine {
	PVOID** ppOpcodeList = (PVOID**)((std::ptrdiff_t)gameBase + 0x45ea5a);
	BYTE* pOpcodeListSize = (BYTE*)((std::ptrdiff_t)gameBase + 0x45ea4d);
	PVOID opcodeDefaultOutput = (PVOID)((std::ptrdiff_t)gameBase + 0x45f79a);

	PVOID OPCODE_FUNCTIONS[44];

	DWORD OpcodeStartLuaThread() {
		LuaMachine::StartLuaThread();

		return c_call<int>(JassMachine::opcodeDefaultOutput);
	}

	void JassOpcodeInitialize() {
		CopyMemory(OPCODE_FUNCTIONS, *ppOpcodeList, sizeof(OPCODE_FUNCTIONS));

		OPCODE_FUNCTIONS[OPTYPE_STARTLUATHREAD - 2] = OpcodeStartLuaThread; // My own opcode function

		DWORD dwOldProtect;
		VirtualProtect(pOpcodeListSize, sizeof(BYTE), PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*pOpcodeListSize = sizeof(OPCODE_FUNCTIONS) / sizeof(PVOID) - 1;
		VirtualProtect(pOpcodeListSize, sizeof(BYTE), dwOldProtect, &dwOldProtect);

		VirtualProtect(ppOpcodeList, sizeof(PVOID), PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*ppOpcodeList = OPCODE_FUNCTIONS;
		VirtualProtect(ppOpcodeList, sizeof(PVOID), dwOldProtect, &dwOldProtect);
	}

	//-----------------------------------------------------------

	PJASS_THREAD_LOCAL GetJassThreadLocal() {
		return (PJASS_THREAD_LOCAL)GetInstance(5);
	}

	PJASS_INSTANCE GetJassMachine(UINT index) {
		std::ptrdiff_t jass_thread = *(std::ptrdiff_t*)(*(UINT*)((std::ptrdiff_t)GetJassThreadLocal() + 0x90) + index * 4);

		return jass_thread ? (PJASS_INSTANCE)jass_thread : NULL;
	}

	PJASS_INSTANCE GetJassInstance() {
		HANDLE instance = GetJassThreadLocal();

		return *(std::ptrdiff_t*)((std::ptrdiff_t)instance + 0x14) ? *(PJASS_INSTANCE*)(*(std::ptrdiff_t*)((std::ptrdiff_t)instance + 0xc) + *(UINT*)((std::ptrdiff_t)instance + 0x14) * 4 - 4) : NULL;
	}
}