#pragma once

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define LINE_STRING TOSTRING(__LINE__)

#define DEBUG_INFO "[" __FILE__ ":" LINE_STRING "]"

namespace Logger {
	enum LOG_LEVEL {
		LOG_NONE,
		LOG_INFO,
		LOG_ERROR,
		LOG_DEBUG,
		LOG_WARNING
	};

	void OpenConsole(std::string name = "");

	void CloseConsole();

	void ClearConsole();

	void Log(LOG_LEVEL level, std::string format, ...);

	std::string format(std::string format, ...);
}