#include "basenException.hpp"

namespace Basen {

	BasenException::BasenException(std::string t_message) {
		this->m_exceptionMessage = t_message;
	}

	const std::string& BasenException::getMessage() {
		return this->m_exceptionMessage;
	}

}