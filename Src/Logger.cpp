#include "pch.h"
#include "Logger.h"

namespace Logger {
	bool isConsole = false;

	void OpenConsole(std::string name) {
		if (isConsole) {
			return;
		}

		AllocConsole();
		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

		SetConsoleCP(65001);
		SetConsoleOutputCP(65001);

		if (!name.empty()) {
			SetConsoleTitle(name.c_str());
		}

		isConsole = true;
	}

	void CloseConsole() {
		if (!isConsole) {
			return;
		}

		fclose(stdin);
		fclose(stdout);
		fclose(stderr);

		HWND console = GetConsoleWindow();
		FreeConsole();
		CloseWindow(console);

		isConsole = false;
	}

	void ClearConsole() {
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

	void Log(std::string info, LEVEL level) {
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD color = NULL;
		LPCSTR text = NULL;

		switch (level)
		{
		case LEVEL::LOG_INFO:
			color |= FOREGROUND_GREEN;
			text = "Info";

			break;
		case LEVEL::LOG_ERROR:
			color |= FOREGROUND_RED;
			text = "Error";

			break;
		case LEVEL::LOG_DEBUG:
			color |= FOREGROUND_BLUE;
			text = "Debug";

			break;
		case LEVEL::LOG_WARNING:
			color |= FOREGROUND_RED | FOREGROUND_GREEN;
			text = "Warning";

			break;
		}

		if (text) {
			std::cout << "[";
			SetConsoleTextAttribute(console, color);
			std::cout << text;
			SetConsoleTextAttribute(console, 15);
			std::cout << "] ";
		}

		std::cout << info << std::endl;
	}
}