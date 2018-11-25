#include "component.hpp"

namespace Basen {

	Component::Component(const ComponentType& t_type)
		: m_type(t_type)
	{}

	Component::~Component()
	{}

	ComponentType Component::getType() const
	{
		return m_type;
	}

	std::stringstream& operator>>(std::stringstream& t_stream, Component& t_component)
	{
		t_component.readIn(t_stream);
		return t_stream;
	}

}