#pragma once
#include <SFML/System/Vector2.hpp>

namespace Bullet
{
	enum class MovementDirection;

	class IBullet
	{
	public:
		virtual void initialize(sf::Vector2f position, MovementDirection direction) = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		virtual ~IBullet() {};
	};
}