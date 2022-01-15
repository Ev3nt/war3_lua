#pragma once

#include <Windows.h>

DWORD __fastcall jassEntryPoint(DWORD a);

DWORD __stdcall getWarcraftID();

BOOL __fastcall isFrameValid(UINT frame, UINT, UINT eventcode);

BOOL __fastcall frameEventObserver(UINT frame, UINT, DWORD eventaddress);