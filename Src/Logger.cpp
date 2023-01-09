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
			SetConsoleTitle(name.data());
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

	std::string Log(std::string info, LEVEL level) {
		std::string message;
		std::string color;

		switch (level)
		{
		case LEVEL::LOG_INFO:
			message = "INFO";
			color = "33FF33";

			break;
		case LEVEL::LOG_ERROR:
			message = "ERROR";
			color = "CC0033";

			break;
		case LEVEL::LOG_DEBUG:
			message = "DEBUG";
			color = "00CCFF";

			break;
		case LEVEL::LOG_WARNING:
			message = "WARNING";
			color = "FF9933";

			break;
		}

		if (!color.empty()) {
			//info = "[|cFF" + color + message + "|r] " + info;
			SYSTEMTIME time;
			GetLocalTime(&time);
			info = Utils::format("[%02d:%02d:%02d] [%s|cFF%s%s|r]: %s", time.wHour, time.wMinute, time.wSecond, isUjAPI ? "|cFF4287F5Lua|r " : "", color.data(), message.data(), info.data());
		}

		Utils::printf("%s\n", info.data());

		return info;
	}
}