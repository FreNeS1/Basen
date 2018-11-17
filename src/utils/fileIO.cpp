#include "fileIO.hpp"

namespace Basen {
	std::string FileIO::getWorkingDirectory()
	{
		HMODULE hModule = GetModuleHandle(nullptr);
		if (!hModule) { return ""; }
		char path[256];
		GetModuleFileName(hModule, path, sizeof(path));
		PathRemoveFileSpec(path);
		strcat_s(path, "");
		return std::string(path);
	}

	std::vector<std::string> FileIO::getFileList(const std::string & t_directory, const std::string & t_search)
	{
		std::vector<std::string> files;
		if (t_search.empty()) { return files; }
		std::string path = t_directory + t_search;
		WIN32_FIND_DATA data;
		HANDLE found = FindFirstFile(path.c_str(), &data);
		if (found == INVALID_HANDLE_VALUE) { return files; }
		do {
			if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				files.emplace_back(data.cFileName);
			}
		} while (FindNextFile(found, &data));
		FindClose(found);
		return files;
	}

	std::string FileIO::prepareLogFile(const std::string & t_logFileName)
	{
		return FileIO::prepareDirectory(FileIO::getWorkingDirectory() + "\\" + config::path::LOGGER_PATH) + t_logFileName;
	}

	std::string FileIO::prepareDirectory(const std::string & t_absolutePath)
	{
		const char* directoryPath = t_absolutePath.c_str();
		if (!CreateDirectory(directoryPath, NULL) && ERROR_ALREADY_EXISTS != GetLastError()) {
			throw IOException("Could not open or prepare directory");
		}
		return std::string(directoryPath);
	}
}