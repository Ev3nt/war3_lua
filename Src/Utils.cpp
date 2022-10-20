#include "pch.h"

namespace Utils {
	std::string format(std::string format, ...) {
		std::vector<char> buffer;
		size_t lenght = 63;
		va_list args;

		while (buffer.size() <= lenght) {
			buffer.resize(lenght + 1);
			va_start(args, format);
			int status = vsnprintf(buffer.data(), buffer.size(), format.c_str(), args);
			va_end(args);
			lenght = (size_t)status;
		}

		return std::string(buffer.data(), lenght);
	}
}