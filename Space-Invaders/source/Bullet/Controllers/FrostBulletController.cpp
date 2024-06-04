#include "../../header/Bullet/Controllers/FrostBulletController.h"
#include "../../header/Bullet/BulletModel.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBulletController::FrostBulletController(BulletType bullet_type, Entity::EntityType owner_type) : BulletController(bullet_type, owner_type) { }

		FrostBulletController::~FrostBulletController() { }

		void FrostBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(frost_bullet_movement_speed);
		}
	}
}