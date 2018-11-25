#ifndef BITMASK_HPP
#define BITMASK_HPP

#include <stdint.h>

namespace Basen {
	using Bitset = uint32_t;

	class Bitmask {
	public:
		Bitmask();
		Bitmask(const Bitset& t_bits);

		Bitset getMask() const;
		void setMask(const Bitset& t_value);

		bool matches(const Bitmask& t_bits, const Bitset& t_relevant = 0) const;

		bool getBit(unsigned int t_pos) const;
		void turnOnBit(unsigned int t_pos);
		void turnOnBits(const Bitset& t_bits);
		void clearBit(unsigned int t_pos);
		void toggleBit(unsigned int t_pos);
		void clear();
	
	private:
		Bitset m_bits;
	};

}

#endif