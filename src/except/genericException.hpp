#ifndef GENERIC_EXCEPTION_HPP
#define GENERIC_EXCEPTION_HPP

#include <string>

namespace Basen {

	class GenericException {

	public:
		explicit			GenericException(std::string t_message);
		const std::string&	getMessage();

	private:
		std::string		m_exceptionMessage;
	};

}

#endif //GENERIC_EXCEPTION_HPP