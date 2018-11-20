#include "miscelaneous.hpp"

namespace Basen {

	void ReadQuotedString(std::stringstream& t_stream, std::string& t_string)
	{
		t_stream >> t_string;
		if (t_string.at(0) == '"') {
			while (t_string.at(t_string.length() - 1) != '"' || !t_stream.eof())
			{
				std::string str;
				t_stream >> str;
				t_string.append(" " + str);
			}
		}
		t_string.erase(std::remove(t_string.begin(), t_string.end(), '"'), t_string.end());
	}

	template<class T>
	T Interpolate(const T& t_x0, const T& t_x1, float t_y0, float t_y1, float t_y)
	{
		return static_cast<T>((((t_x1 - t_x0) / (t_y1 - t_y0)) * (t_y - t_y0)) + t_x0);
	}

}