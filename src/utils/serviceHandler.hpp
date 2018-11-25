#ifndef SERVICE_HANDLER_HPP
#define SERVICE_HANDLER_HPP

#include "logger.hpp"

namespace Basen {
	class ServiceHandler
	{
	public:
		static void setLogger(Logger *t_logger);
		static Logger& getLogger();

	private:
		static std::unique_ptr<Logger> m_logger;
	};
}

#endif // SERVICE_HANDLER_HPP
