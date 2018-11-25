#ifndef COMPONENT_TYPE_HPP
#define COMPONENT_TYPE_HPP

namespace Basen {
	enum class ComponentType
	{
		Position = 0,
		SpriteSheet,
		State,
		Movable,
		Controller,
		Collidable,
		SoundEmitter,
		SoundListener,
		COUNT
	};
}

#endif // COMPONENT_TYPE_HPP
