#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/BulletConfig.h"


namespace Bullet
{
	using namespace Entity;

	namespace Controllers
	{
		LaserBulletController::LaserBulletController(BulletType type, EntityType owner_type) : BulletController(type, owner_type)
		{
		}
		LaserBulletController::~LaserBulletController()
		{
		}
		void LaserBulletController::initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::initialize(position, direction);
		}
	}
}