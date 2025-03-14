#include "../../Header/Bullet/BulletConfig.h"

namespace Bullet
{
	const sf::String BulletConfig::laser_bullet_texture_path = "assets/textures/laser_bullet.png";

	const sf::String BulletConfig::torpedoe_texture_path = "assets/textures/torpedoe.png";

	const sf::String BulletConfig::frost_beam_texture_path = "assets/textures/frost_beam.png";

	sf::String BulletConfig::getBulletTexturePath(BulletType type)
	{
		switch (type)
		{
		case BulletType::LASER:
			return laser_bullet_texture_path;

		case BulletType::TORPEDO:
			return torpedoe_texture_path;

		case BulletType::FROST:
			return frost_beam_texture_path;
		}
	}
}


