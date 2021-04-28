#include "Jass.h"
#include "Variables.h"

jReal to_jReal(float fX)
{
	return *(jReal*)&fX;
}

jString to_jString(LPCSTR lpString)
{
	UINT32* string = new UINT32[8];

	string[2] = (UINT32)&string[0];
	string[7] = (UINT32)&lpString[0];

	return (jString)string;
}

LPCSTR from_jString(jString string)
{
	if (!string)
		return NULL;

	return *(LPCSTR*)((UINT32*)string)[7];
}

jInteger to_ID(LPCSTR lpID)
{
	return lpID[0] * 256 * 256 * 256 + lpID[1] * 256 * 256 + lpID[2] * 256 + lpID[3];
}

//---------------------------------------------------------

HTIMER __declspec(naked) CreateTimer()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d0500
		jmp eax
	}
}

jNothing __declspec(naked) TimerStart(HTIMER whichTimer, jReal* timeout, jBoolean periodic, jCode handlerFunc)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c1370
		jmp eax
	}
}

HPLAYER __declspec(naked) Player(jInteger number)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3bbb30
		jmp eax
	}
}

jNothing __declspec(naked) DisplayTimedTextToPlayer(HPLAYER toPlayer, jReal* x, jReal* y, jReal* duration, jString message)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3cb9b0
		jmp eax
	}
}

HUNIT __declspec(naked) CreateUnit(HPLAYER id, jInteger unitid, jReal* x, jReal* y, jReal* face)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c5230
		jmp eax
	}
}

HTRIGGERACTION __declspec(naked) TriggerAddAction(jTrigger whichTrigger, jCode actionFunc)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c3e90
		jmp eax
	}
}

jTrigger __declspec(naked) CreateTrigger()
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d11f0
		jmp eax
	}
}

HEVENT __declspec(naked) TriggerRegisterPlayerEvent(jTrigger whichTrigger, HPLAYER whichPlayer, HPLAYEREVENT whichPlayerEvent)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1c90
		jmp eax
	}
}

HEVENT __declspec(naked) TriggerRegisterPlayerChatEvent(jTrigger whichTrigger, HPLAYER whichPlayer, jString chatMessageToDetect, jBoolean exactMatchOnly)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3d1ef0
		jmp eax
	}
}

HTRIGGERCONDITION __declspec(naked) TriggerAddCondition(jTrigger whichTrigger, HBOOLEXPR condition)
{
	_asm {
		mov eax, hGame
		add eax, 0x3c3df0
		jmp eax
	}
}

HBOOLEXPR __declspec(naked) Condition(jCode actionFunc)
{
	_asm {
		mov eax, hGame
		add eax, 0x3bb0a0
		jmp eax
	}
}

HPLAYEREVENT __declspec(naked) ConvertPlayerEvent(jInteger i)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3b26b0
		jmp eax
	}
}

/*jString __declspec(naked) GetPlayerName(HPLAYER whichPlayer)
{
	_asm
	{
		mov eax, hGame
		add eax, 0x3c0f60
		jmp eax
	}
}*/

// Rewrited
LPCSTR __declspec(naked) GetPlayerName(HPLAYER whichPlayer)
{
	_asm
	{
		mov ecx, [esp + 4]
		mov eax, hGame
		add eax, 0x3bd4d0
		call eax
		test eax, eax
		jne pSuccessful
		ret
	pSuccessful :
		push 1
		mov ecx, eax
		mov eax, hGame
		add eax, 0x40aff0
		call eax
		ret
	}
}