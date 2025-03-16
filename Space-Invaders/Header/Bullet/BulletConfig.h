#pragma once
#include <SFML/Graphics.hpp>

namespace Bullet
{
	enum class BulletType
	{
		LASER,
		TORPEDO,
		FROST
	};

	enum class MovementDirection
	{
		UP,
		DOWN
	};

	class BulletConfig
	{
	private:
		static const sf::String laser_bullet_texture_path;
		static const sf::String torpedoe_texture_path;
		static const sf::String frost_beam_texture_path;

	public:

		static const sf::String getBulletTexturePath(BulletType type);
	};
}
