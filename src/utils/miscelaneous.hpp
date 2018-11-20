#ifndef MISCELANEOUS_HPP
#define MISCELANEOUS_HPP

#include <string>
#include <algorithm>
#include <sstream>

namespace Basen {

	void	ReadQuotedString(std::stringstream& l_stream, std::string& l_string);

	template<class T>
	T		Interpolate(float tBegin, float tEnd, const T& begin_val, const T& end_val, float tX);
}

#endif // MISCELANEOUS_HPP
