#ifndef IO_EXCEPTION_HPP
#define IO_EXCEPTION_HPP

#include <string>
#include "genericException.hpp"

namespace Basen {

	class IOException : public GenericException {

	public:
		explicit		IOException(std::string t_message);
	};

}

#endif //IO_EXCEPTION_HPP