#include "random.hpp"

namespace Basen {

	RandomGenerator::RandomGenerator()
		: m_engine(m_device())
	{}

	float RandomGenerator::operator()(float t_min, float t_max)
	{
		return generate(t_min, t_max);
	}

	int RandomGenerator::operator()(int t_min, int t_max)
	{
		return generate(t_min, t_max);
	}

	int RandomGenerator::generate(int t_min, int t_max)
	{
		sf::Lock lock(m_mutex);
		if (t_min > t_max) { std::swap(t_min, t_max); }
		if (t_min != m_intDistribution.min() || t_max != m_intDistribution.max())
		{
			m_intDistribution = std::uniform_int_distribution<int>(t_min, t_max);
		}
		return m_intDistribution(m_engine);
	}

	float RandomGenerator::generate(float t_min, float t_max)
	{
		sf::Lock lock(m_mutex);
		if (t_min > t_max) { std::swap(t_min, t_max); }
		if (t_min != m_floatDistribution.min() || t_max != m_floatDistribution.max())
		{
			m_floatDistribution = std::uniform_real_distribution<float>(t_min, t_max);
		}
		return m_floatDistribution(m_engine);
	}

}