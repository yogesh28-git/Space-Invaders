#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Bullet/BulletModel.h"

namespace Bullet
{
	using namespace Entity;

	namespace Controllers
	{
		TorpedoeController::TorpedoeController(BulletType type, EntityType owner_type) : BulletController(type, owner_type)
		{

		}
		TorpedoeController::~TorpedoeController()
		{

		}
		void TorpedoeController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			bullet_model->setMovementSpeed(torpedoe_movement_speed);
		}
	}
}