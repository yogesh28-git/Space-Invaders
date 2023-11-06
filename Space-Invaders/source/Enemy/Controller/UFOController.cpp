#include "../../header/Enemy/Controller/UFOController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;

	namespace Controller
	{
		UFOController::UFOController(EnemyType type) : EnemyController(type) { }

		UFOController::~UFOController() { }

		void UFOController::initialize()
		{
			EnemyController::initialize();
		}

		void UFOController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void UFOController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += horizontal_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void UFOController::moveDown() { }

		void UFOController::moveDiagonalLeft() { }

		void UFOController::moveDiagonalRight() { }

		void UFOController::fireBullet() { }
	}
}
