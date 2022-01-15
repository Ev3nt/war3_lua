#include "Utils.h"
#include "Global.h"
#include <iostream>

bool openConsole(LPCSTR title) {
	FILE* console;

	bool result = AllocConsole() && !freopen_s(&console, "CONOUT$", "w", stdout);

	SetConsoleTitle(title);

	return result;
}

void clearConsole() {
	HANDLE hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD count;
	DWORD cellCount;
	COORD homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) {
		return;
	}

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		return;
	}

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	if (!FillConsoleOutputCharacter(hStdOut, ' ', cellCount, homeCoords, &count)) {
		return;
	}

	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) {
		return;
	}

	SetConsoleCursorPosition(hStdOut, homeCoords);
}