#pragma once

void PrintChat(LPCSTR text, float duration);
void PrintfChat(float duration, LPCSTR format, ...);
HANDLE GetInstance(UINT index);
LPVOID ConvertHandle(UINT handle);