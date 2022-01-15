#include "JassMachine.h"

#include "Variables.h"
#include "Mem.h"
#include "LuaMachine.h"

DWORD OPCODES_FUNCTIONS[44];

DWORD _declspec(naked) jassOpcodeStartLuaThread() {
	_asm {
		push edi
		push esi
		call startLuaThread

		sub esp, 8
		mov[esp], eax
		add esp, 8
		mov eax, gameBase
		add eax, 0x45f79a
		push eax
		sub esp, 4
		pop eax

		ret
	}
}
// game.dll + 45969d
void jassOpcodeInitialize() {
	DWORD overflow = MakePtr(gameBase, _overflowOpcodeProc);
	memcpy(OPCODES_FUNCTIONS, (LPVOID)MakePtr(gameBase, _opcodeList), sizeof(OPCODES_FUNCTIONS));
	OPCODES_FUNCTIONS[42] = overflow;
	OPCODES_FUNCTIONS[43] = (DWORD)jassOpcodeStartLuaThread; // My own opcode function

	DWORD dwOldProtect;
	DWORD address = MakePtr(gameBase, _opcodeListSize);
	VirtualProtect((LPVOID)address, 1, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(BYTE*)address = sizeof(OPCODES_FUNCTIONS) / 4 - 1;
	VirtualProtect((LPVOID)address, 1, dwOldProtect, &dwOldProtect);

	address = MakePtr(gameBase, _opcodeSwitch);
	VirtualProtect((LPVOID)address, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(DWORD*)address = (DWORD)OPCODES_FUNCTIONS;
	VirtualProtect((LPVOID)address, 4, dwOldProtect, &dwOldProtect);
}