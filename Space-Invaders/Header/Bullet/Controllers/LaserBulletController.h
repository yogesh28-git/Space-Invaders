#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controllers
	{
		class LaserBulletController : public BulletController
		{
		public:

			LaserBulletController(BulletType type, Entity::EntityType owner_type);
			~LaserBulletController() override;

			void initialize(sf::Vector2f position, MovementDirection direction) override;
		};
	}
}
