#pragma once

#include "../pch.h"

namespace Storm {
	class Archive {
	public:
		Archive();
		~Archive(); // It's calling close if we're owner of archive

		void Open(std::string name, DWORD priority = 13, DWORD flags = 0);
		void Connect(HANDLE handle);

		void Close(bool force = false);
		std::string GetArchiveName();
		std::string GetArchiveName(std::string fileName);

		std::string operator[](std::string name); // Open file such as string
	private:
		HANDLE m_handle = NULL;
		bool m_owner = false; // We're owner, if we have opened archive
	};
}