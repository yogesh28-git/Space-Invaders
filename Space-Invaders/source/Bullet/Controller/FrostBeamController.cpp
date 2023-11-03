#include "../../header/Bullet/Controller/FrostBeamController.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBeamController::FrostBeamController(BulletType bullet_type, Entity::EntityType owner_type) : BulletController(bullet_type, owner_type) { }

		FrostBeamController::~FrostBeamController() { }

		void FrostBeamController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			movement_speed = 400.f;
		}
	}
}