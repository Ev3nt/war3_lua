#include "JassMachine.h"

#include "Variables.h"
#include "Mem.h"
#include "LuaMachine.h"

DWORD OPCODES_FUNCTIONS[44];

DWORD _declspec(naked) JassOpcodeStartLuaThread()
{
	_asm {
		push edi
		push esi
		call StartLuaThread

		sub esp, 8
		mov[esp], eax
		add esp, 8
		mov eax, hGame
		add eax, 0x45f79a
		push eax
		sub esp, 4
		pop eax

		ret
	}
}

void JassOpcodeInitialize()
{
	DWORD overflow = MakePtr(hGame, _OverflowOpcodeProc);
	memcpy(OPCODES_FUNCTIONS, (LPVOID)MakePtr(hGame, _OpcodeList), sizeof(OPCODES_FUNCTIONS));
	OPCODES_FUNCTIONS[42] = overflow;
	OPCODES_FUNCTIONS[43] = (DWORD)JassOpcodeStartLuaThread; // My own opcode function

	DWORD dwOldProtect;
	DWORD address = MakePtr(hGame, _OpcodeListSize);
	VirtualProtect((LPVOID)address, 1, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(BYTE*)address = sizeof(OPCODES_FUNCTIONS) / 4 - 1;
	VirtualProtect((LPVOID)address, 1, dwOldProtect, &dwOldProtect);

	address = MakePtr(hGame, _OpcodeSwitch);
	VirtualProtect((LPVOID)address, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*(DWORD*)address = (DWORD)OPCODES_FUNCTIONS;
	VirtualProtect((LPVOID)address, 4, dwOldProtect, &dwOldProtect);
}