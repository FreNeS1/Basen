#include "IOException.hpp"

namespace Basen {

	IOException::IOException(std::string t_message)
		: GenericException(t_message)
	{}

}