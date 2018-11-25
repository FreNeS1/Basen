#ifndef IO_EXCEPTION_HPP
#define IO_EXCEPTION_HPP

#include <string>
#include "basenException.hpp"

namespace Basen {

	class IOException : public BasenException {

	public:
		explicit		IOException(std::string t_message);
	};

}

#endif //IO_EXCEPTION_HPP
