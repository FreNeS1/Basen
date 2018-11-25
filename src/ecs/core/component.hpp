#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <sstream>

#include "componentType.hpp"

namespace Basen {
	class Component {
	public:
		Component(const ComponentType& t_type);
		virtual	~Component();

		ComponentType getType() const;
		friend std::stringstream& operator>>(std::stringstream& t_stream, Component& t_component);

	private:
		virtual void readIn(std::stringstream& l_stream) = 0;

	protected:
		ComponentType m_type;
	};
}

#endif // COMPONENT_HPP
