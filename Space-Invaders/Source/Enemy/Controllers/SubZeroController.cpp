#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"

namespace Enemy {

	namespace Controllers {

		using namespace Global;
		using namespace Bullet;

		void SubZeroController::move()
		{
			switch (enemy_model->getMovementDirection()) {
			case MovementDirection::DOWN: 
				moveDown();
				break;
			}
		}
		void SubZeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += vertical_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}
		SubZeroController::SubZeroController(EnemyType type) : EnemyController(type)
		{
		}
		SubZeroController::~SubZeroController()
		{
		}
		void SubZeroController::fireBullet()
		{
			ServiceLocator::getInstance()->getBulletService()->spawnBullet(BulletType::LASER, Entity::EntityType::ENEMY, enemy_model->getEnemyPosition() + getBarrelPositionOffset(), Bullet::MovementDirection::DOWN);
		}
		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			rate_of_fire = subzero_rate_of_fire;
		}
	}
}