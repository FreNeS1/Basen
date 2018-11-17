#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include <string>
#include <vector>
#include <windows.h>
#include <shlwapi.h>

#include "../config/config.hpp"
#include "../except/IOException.hpp"

namespace Basen {
	class FileIO
	{
	public:
		static std::string					getWorkingDirectory();
		static std::vector<std::string>		getFileList(const std::string& t_directory, const std::string& t_search = "*.*");
		static std::string					prepareLogFile(const std::string& t_logFileName);

	private:
		static std::string					prepareDirectory(const std::string& t_absolutePath);
	};
}

#endif // FILE_IO_HPP
