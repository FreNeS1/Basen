#ifndef MISC_HPP
#define MISC_HPP

#include <string>
#include <algorithm>
#include <sstream>

namespace Basen {

	void ReadQuotedString(std::stringstream& l_stream, std::string& l_string);

	template<class T>
	T Interpolate(const T& t_x0, const T& t_x1, float t_y0, float t_y1, float t_y);

}

#endif // MISC_HPP
