#include "serviceHandler.hpp"

namespace Basen {
	std::unique_ptr<Logger> ServiceHandler::m_logger(nullptr);

	void ServiceHandler::setLogger(Logger * t_logger)
	{
		ServiceHandler::m_logger.reset(t_logger);
	}

	Logger& ServiceHandler::getLogger()
	{
		return *ServiceHandler::m_logger;
	}
}

