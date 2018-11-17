#include "genericException.hpp"

namespace Basen {

	GenericException::GenericException(std::string t_message) {
		this->m_exceptionMessage = t_message;
	}

	const std::string& GenericException::getMessage() {
		return this->m_exceptionMessage;
	}

}