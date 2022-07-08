#pragma once

#include "../pch.h"

HMODULE stormBase = LoadLibrary("storm.dll");

auto StormCloseArchive = (BOOL(WINAPI*)(HANDLE archive))(GetProcAddress(stormBase, (LPCSTR)252));
auto StormCloseFile = (BOOL(WINAPI*)(HANDLE file))(GetProcAddress(stormBase, (LPCSTR)253));
auto StormGetFileArchive = (SIZE_T(WINAPI*)(HANDLE file, HANDLE* archive))(GetProcAddress(stormBase, (LPCSTR)264));
auto StormGetFileSize = (SIZE_T(WINAPI*)(HANDLE file, LPDWORD filesizehigh))(GetProcAddress(stormBase, (LPCSTR)265));
auto StormOpenArchive = (BOOL(WINAPI*)(LPCSTR archivename, DWORD priority, DWORD flags, HANDLE* handle))(GetProcAddress(stormBase, (LPCSTR)266));
auto StormOpenFileEx = (BOOL(WINAPI*)(HANDLE archive, LPCSTR filename, DWORD mode, HANDLE* handle))(GetProcAddress(stormBase, (LPCSTR)268));
auto StormReadFile = (BOOL(WINAPI*)(HANDLE file, PVOID buffer, SIZE_T bumberofbytestoread, SIZE_T* read, LONG distancetomovehigh))(GetProcAddress(stormBase, (LPCSTR)269));
auto StormGetArchiveName = (BOOL(WINAPI*)(HANDLE archive, LPSTR name, SIZE_T length))(GetProcAddress(stormBase, (LPCSTR)275));
auto StormGetFileName = (BOOL(WINAPI*)(HANDLE file, LPSTR buffer, SIZE_T length))(GetProcAddress(stormBase, (LPCSTR)276));
auto StormOpenFile = (BOOL(WINAPI*)(LPCSTR filename, HANDLE* file))(GetProcAddress(stormBase, (LPCSTR)267));