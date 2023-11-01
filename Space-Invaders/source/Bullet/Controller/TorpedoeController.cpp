#include "../../header/Bullet/Controller/TorpedoeController.h"

namespace Bullet
{
	namespace Controller
	{
		TorpedoeController::TorpedoeController(BulletType type) : BulletController(type) { }

		TorpedoeController::~TorpedoeController() { }

		void TorpedoeController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			movement_speed = 100.f;
		}
	}
}