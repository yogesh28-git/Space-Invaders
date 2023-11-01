#include "../../header/Bullet/Controller/FrostBeamController.h"

namespace Bullet
{
	namespace Controller
	{
		FrostBeamController::FrostBeamController(BulletType type) : BulletController(type) { }

		FrostBeamController::~FrostBeamController() { }

		void FrostBeamController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
			movement_speed = 200.f;
		}
	}
}