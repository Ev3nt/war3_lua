#include "pch.h"
#include "Logger.h"

namespace Logger {
	void OpenConsole(std::string name) {
		AllocConsole();
		freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
		freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
		freopen_s((FILE**)stderr, "CONOUT$", "w", stderr);

		SetConsoleCP(65001);
		SetConsoleOutputCP(65001);

		if (!name.empty()) {
			SetConsoleTitle(name.c_str());
		}
	}

	void CloseConsole() {
		fclose(stdin);
		fclose(stdout);
		fclose(stderr);
		FreeConsole();
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

	void Log(LEVEL level, std::string format, ...) {
		char buffer[8192] = { 0 };

		va_list args;
		va_start(args, format);
		vsprintf_s(buffer, format.c_str(), args);
		va_end(args);

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

		std::cout << buffer << std::endl;
	}

	std::string format(std::string format, ...) {
		va_list args;
		va_start(args, format);

		char buffer[8192];
		vsprintf_s(buffer, format.c_str(), args);

		va_end(args);

		return std::string(buffer);
	}
}