#include "JassMachine.h"
#include "LuaMachine.h"
#include "Global.h"

PVOID** ppOpcodeList = (PVOID**)((UINT_PTR)gameBase + 0x45ea5a);
BYTE* pOpcodeListSize = (BYTE*)((UINT_PTR)gameBase + 0x45ea4d);
PVOID opcodeDefaultOut = (PVOID)((UINT_PTR)gameBase + 0x45f79a);

PVOID OPCODE_FUNCTIONS[44];

DWORD _declspec(naked) opcodeStartLuaThread() {
	_asm {
		push esi
		call startLuaThread

		push opcodeDefaultOut
		ret
	}
}

void jassOpcodeInitialize() {
	 memcpy(OPCODE_FUNCTIONS, *ppOpcodeList, sizeof(OPCODE_FUNCTIONS));

	 OPCODE_FUNCTIONS[OPTYPE_STARTLUATHREAD - 2] = opcodeStartLuaThread; // My own opcode function

	 DWORD dwOldProtect;
	 VirtualProtect(pOpcodeListSize, 1, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	 *pOpcodeListSize = sizeof(OPCODE_FUNCTIONS) / 4 - 1;
	 VirtualProtect(pOpcodeListSize, 1, dwOldProtect, &dwOldProtect);

	 VirtualProtect(ppOpcodeList, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	 *ppOpcodeList = OPCODE_FUNCTIONS;
	 VirtualProtect(ppOpcodeList, 4, dwOldProtect, &dwOldProtect);
}