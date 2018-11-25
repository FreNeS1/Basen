#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Clock.hpp>

#include "../exceptions/IOException.hpp"
#include "fileIO.hpp"

namespace Basen {

	class Logger : private sf::NonCopyable {

	public:
		enum class logType { LOG_FATAL, LOG_ERROR, LOG_WARNING, LOG_INFO, LOG_DEBUG, LOG_TRACE};

		explicit Logger(const std::string &t_version, const std::string &t_fileName);
		~Logger();

		void trace(const std::string &t_message);
		void debug(const std::string &t_message);
		void log(const std::string &t_message);
		void warn(const std::string &t_message);
		void error(const std::string &t_message);
		void fatal(const std::string &t_message);

	private:
		void writeToFile(const std::string t_message);
		void buildLoggerMessage(const logType t_logType, std::string &t_rawMessage);

	private:
		sf::Clock m_loggerClock;
		std::ofstream m_outputFile;
		unsigned int m_numErrors;
		unsigned int m_numWarnings;
	};

}

#endif // LOGGER_HPP