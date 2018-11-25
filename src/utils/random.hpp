#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>
#include <SFML/System/Mutex.hpp>
#include <SFML/System/Lock.hpp>

namespace Basen {
	class RandomGenerator {
	public:
		RandomGenerator();

		float operator()(float t_min, float t_max);
		int operator()(int t_min, int t_max);
		int generate(int t_min, int t_max);
		float generate(float t_min, float t_max);

	private:
		std::random_device m_device;
		std::mt19937 m_engine;
		std::uniform_int_distribution<int> m_intDistribution;
		std::uniform_real_distribution<float> m_floatDistribution;
		sf::Mutex m_mutex;
	};
}

#endif // RANDOM_HPP