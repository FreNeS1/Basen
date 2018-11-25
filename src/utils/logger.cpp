#include "logger.hpp"

namespace Basen {
	Logger::Logger(const std::string &t_version, const std::string &t_fileName)
		: m_numWarnings(0U)
		, m_numErrors(0U)
	{
		m_outputFile.open(FileIO::prepareLogFile(t_fileName));

		if (m_outputFile.is_open()) {
			this->writeToFile("Basen engine - v " + t_version);
			this->writeToFile("Log file created");
			this->writeToFile("");
		}
	}

	Logger::~Logger() {
		if (m_outputFile.is_open()) {
			this->writeToFile("");
			this->writeToFile("Application closed with:");
			this->writeToFile(std::to_string(m_numWarnings) + " warnings");
			this->writeToFile(std::to_string(m_numErrors) + " errors");
			m_outputFile.close();
		}
	}

	void Logger::trace(const std::string &t_message) {
		std::string message = t_message;
		this->buildLoggerMessage(Logger::logType::LOG_TRACE, message);
		this->writeToFile(message);
	}

	void Logger::debug(const std::string &t_message) {
		std::string message = t_message;
		this->buildLoggerMessage(Logger::logType::LOG_DEBUG, message);
		this->writeToFile(message);
	}

	void Logger::log(const std::string &t_message) {
		std::string message = t_message;
		this->buildLoggerMessage(Logger::logType::LOG_INFO, message);
		this->writeToFile(message);
	}

	void Logger::warn(const std::string &t_message) {
		std::string message = t_message;
		this->buildLoggerMessage(Logger::logType::LOG_WARNING, message);
		this->writeToFile(message);
	}

	void Logger::warn(const std::string &t_message) {
		std::string message = t_message;
		this->buildLoggerMessage(Logger::logType::LOG_ERROR, message);
		this->writeToFile(message);
	}

	void Logger::warn(const std::string &t_message) {
		std::string message = t_message;
		this->buildLoggerMessage(Logger::logType::LOG_FATAL, message);
		this->writeToFile(message);
	}

	void Logger::writeToFile(const std::string t_message)
	{
		if (m_outputFile.is_open()) {
			m_outputFile << t_message << std::endl;
		}
		else {
			throw std::make_unique<IOException>("Could not create and open logger file");
		}
	}

	void Logger::buildLoggerMessage(const logType t_logType, std::string &t_rawMessage)
	{
		const std::string logTypeMessage = [&]() {
			if (t_logType == logType::LOG_FATAL) {
				return "FATAL";
			}
			else if (t_logType == logType::LOG_ERROR) {
				return "ERROR";
			}
			else if (t_logType == logType::LOG_WARNING) {
				return "WARNING";
			}
			else if (t_logType == logType::LOG_INFO) {
				return "INFO";
			}
			else if (t_logType == logType::LOG_DEBUG) {
				return "DEBUG";
			}
			else if (t_logType == logType::LOG_TRACE) {
				return "TRACE";
			}
			else {
				return "UNKNOWN";
			}
		}();

		t_rawMessage = "[" + std::to_string(m_loggerClock.getElapsedTime().asMilliseconds()) + " ms] [" + logTypeMessage + "]: " + t_rawMessage;
	}
}
