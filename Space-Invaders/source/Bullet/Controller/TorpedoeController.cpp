#include "../../header/Bullet/Controller/TorpedoeController.h"

namespace Bullet
{
	namespace Controller
	{
		using namespace Entity;

		TorpedoeController::TorpedoeController(BulletType bullet_type, Entity::EntityType owner_type) : BulletController(bullet_type, owner_type) { }

		TorpedoeController::~TorpedoeController() { }

		void TorpedoeController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			movement_speed = 200.f;
		}
	}
}