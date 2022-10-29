#include "pch.h"
#include "JassMachine.h"
#include "LuaMachine.h"
#include "Offsets.h"

namespace JassMachine {
	PVOID OPCODE_FUNCTIONS[44];

	DWORD OpcodeStartLuaThread() {
		LuaMachine::StartLuaThread();

		return c_call<int>(pOffsets[(UINT)Offset::OpcodeDefaultOutput]); // jump
	}

	void JassOpcodeInitialize() {
		PVOID** ppOpcodeList = (PVOID**)(pOffsets[(UINT)Offset::OpcodeList]);
		BYTE* pOpcodeListSize = (BYTE*)(pOffsets[(UINT)Offset::OpcodeSize]);
		
		CopyMemory(OPCODE_FUNCTIONS, *ppOpcodeList, sizeof(OPCODE_FUNCTIONS));

		OPCODE_FUNCTIONS[(UINT)OPCODE_TYPE::STARTLUATHREAD - 2] = OpcodeStartLuaThread; // My own opcode function

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
		return (PJASS_THREAD_LOCAL)Warcraft::GetTLSValueByIndex(5);
	}

	PJASS_INSTANCE GetJassMachine(UINT index) {
		std::ptrdiff_t jass_thread = *(std::ptrdiff_t*)(*(UINT*)((std::ptrdiff_t)GetJassThreadLocal() + 0x90) + index * 4);

		return jass_thread ? (PJASS_INSTANCE)jass_thread : NULL;
	}

	PJASS_INSTANCE GetJassInstance() {
		HANDLE instance = GetJassThreadLocal();

		return *(std::ptrdiff_t*)((std::ptrdiff_t)instance + 0x14) ? *(PJASS_INSTANCE*)(*(std::ptrdiff_t*)((std::ptrdiff_t)instance + 0xc) + *(UINT*)((std::ptrdiff_t)instance + 0x14) * 4 - 4) : NULL;
	}

	PJASS_VARIABLE GetVariableDataNodeByName(PSCRIPT_DATA_TABLE pDataNode, const std::string& name) {
		return pOffsets[(UINT)Offset::GetjVariableByName] && pDataNode && !name.empty() ? this_call<PJASS_VARIABLE>(pOffsets[(UINT)Offset::GetjVariableByName], pDataNode, name.data()) : NULL;
	}

	PJASS_VARIABLE GetVariableDataNodeByNameEx(PJASS_INSTANCE jvm, const std::string& name) {
		PJASS_VARIABLE pData = (int)(jvm->stack) > NULL ? GetVariableDataNodeByName((PSCRIPT_DATA_TABLE)&jvm->stack[36], name.data()) : NULL; // Check for local first // 0x2868

		return !pData ? GetVariableDataNodeByName(jvm->script_table, name.data()) : pData;
	}
}