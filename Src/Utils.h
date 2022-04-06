#pragma once

#include <windows.h>
#include <string>

std::string utf8_to_cp1251(LPCSTR string);

std::string cp1251_to_utf8(LPCSTR string);

bool openConsole(LPCSTR title);

void clearConsole();