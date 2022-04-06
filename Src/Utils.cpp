#include "Utils.h"
#include "Global.h"
#include <iostream>

std::string cp1251_to_utf8(LPCSTR string) {
	std::string retval;

	if (string) {
		int usize = MultiByteToWideChar(1251, 0, string, -1, 0, 0), csize;

		if (usize) {
			wchar_t* ustring = new wchar_t[usize];
			if (MultiByteToWideChar(1251, 0, string, -1, ustring, usize)) {
				csize = WideCharToMultiByte(CP_UTF8, 0, ustring, -1, 0, 0, 0, 0);
				if (csize) {
					char* cstring = new char[csize];
					if (WideCharToMultiByte(CP_UTF8, 0, ustring, -1, cstring, csize, 0, 0)) {
						retval = cstring;
					}

					delete[] cstring;
				}
			}

			delete[] ustring;
		}
	}

	return retval;
}

std::string utf8_to_cp1251(LPCSTR string) {
	std::string retval;

	if (string) {
		int usize = MultiByteToWideChar(CP_UTF8, 0, string, -1, 0, 0), csize;

		if (usize) {
			wchar_t* ustring = new wchar_t[usize];
			if (MultiByteToWideChar(CP_UTF8, 0, string, -1, ustring, usize)) {
				csize = WideCharToMultiByte(1251, 0, ustring, -1, 0, 0, 0, 0);
				if (csize) {
					char* cstring = new char[csize];
					if (WideCharToMultiByte(1251, 0, ustring, -1, cstring, csize, 0, 0)) {
						retval = cstring;
					}

					delete[] cstring;
				}
			}

			delete[] ustring;
		}
	}

	return retval;
}

bool openConsole(LPCSTR title) {
	FILE* console;

	bool result = AllocConsole() && !freopen_s(&console, "CONOUT$", "w", stdout);

	SetConsoleTitle(title);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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