#include "pch.h"

namespace Utils {
	std::string formatv(std::string format, va_list va) {
		std::string buffer;
		size_t size = 0;

		while ((size = vsnprintf((char*)buffer.data(), size, format.data(), va)) > buffer.size()) {
			buffer.resize(++size);
		}

		return buffer;
	}

	std::string format(std::string format, ...) {
		va_list args;

		va_start(args, format);
		std::string buffer = formatv(format, args);
		va_end(args);
		
		return buffer;
	}

	void printf(std::string format, ...) {
		va_list args;
		va_start(args, format);
		std::string buffer = formatv(format, args) + "|r";
		va_end(args);

		size_t i = 0;
		while ((i = buffer.find_first_of('|', i)) != std::string::npos) {
			std::string color_prefix;
			size_t size;

			switch (buffer[i + 1])
			{
			case 'c':
				DWORD color;
				size = 10;

				if (sscanf_s(&buffer[i + 2], "%08X", &color)) {
					color_prefix = "\x1b[38;2;" + std::to_string((color >> 16) & 0xFF) + ";" + std::to_string((color >> 8) & 0xFF) + ";" + std::to_string(color & 0xFF) + "m";
				}
				else {
					i += size;
				}

				break;

			case 'r':
				color_prefix = "\033[0m";
				size = 2;

				break;
			}

			size_t color_prefix_size = color_prefix.size();
			if (!color_prefix_size) {
				i++;

				continue;
			}

			buffer.replace(i, size, color_prefix);
			i += color_prefix_size;
		}

		std::cout << buffer;
	}
}