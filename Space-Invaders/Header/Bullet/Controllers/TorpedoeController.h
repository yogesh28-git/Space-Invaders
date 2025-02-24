#pragma once
#include "../../Header/Bullet/BulletController.h"

namespace Bullet
{
	namespace Controllers
	{
		class TorpedoeController : public BulletController
		{
		private:
			const float torpedoe_movement_speed = 200.0f;

		public:
			TorpedoeController(BulletType type, Entity::EntityType onwer_type);
			~TorpedoeController() override;

			void initialize(sf::Vector2f position, MovementDirection direction) override;
		};
	}
}
