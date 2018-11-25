#include "bitmask.hpp"

namespace Basen {

	using Bitset = uint32_t;

	Bitmask::Bitmask()
		: m_bits(0)
	{}

	Bitmask::Bitmask(const Bitset& t_bits)
		: m_bits(t_bits)
	{}

	Bitset Bitmask::getMask() const
	{
		return m_bits;
	}

	void Bitmask::setMask(const Bitset& t_value)
	{
		m_bits = t_value;
	}

	bool Bitmask::matches(const Bitmask& t_bits, const Bitset& t_relevant = 0) const
	{
		return(t_relevant ? ((t_bits.getMask() & t_relevant) == (m_bits & t_relevant)) : (t_bits.getMask() == m_bits));
	}

	bool Bitmask::getBit(unsigned int l_pos) const
	{
		return ((m_bits&(1 << l_pos)) != 0);
	}

	void Bitmask::turnOnBit(unsigned int l_pos)
	{
		m_bits |= 1 << l_pos;
	}

	void Bitmask::turnOnBits(const Bitset& l_bits)
	{
		m_bits |= l_bits;
	}

	void Bitmask::clearBit(unsigned int l_pos)
	{
		m_bits &= ~(1 << l_pos);
	}

	void Bitmask::toggleBit(unsigned int l_pos)
	{
		m_bits ^= 1 << l_pos;
	}

	void Bitmask::clear()
	{
		m_bits = 0;
	}
};