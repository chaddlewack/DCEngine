#pragma once

#include <string>

namespace DCEngine {
	
	class FileUtil {
	public:
		// We use standard file and rt to ensure correct line endings.
		static std::string read_file(const char* filepath) {
			FILE* file = fopen(filepath, "rt");
			// We need to calculate the length of the data
			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			// Adding 1 to the length so we can include a termination char
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			// Reset our position back to the start of the data stream
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;

			return result;
		}
	};
}