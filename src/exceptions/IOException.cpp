#include "IOException.hpp"

namespace Basen {

	IOException::IOException(std::string t_message)
		: BasenException(t_message)
	{}

}