#include "../../header/Enemy/Controller/ThunderSnakeController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;

	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type) { }

		ThunderSnakeController::~ThunderSnakeController() { }

		void ThunderSnakeController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setEnemyPosition(initial_position);
		}

		void ThunderSnakeController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT_DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT_DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveDown() { }

		void ThunderSnakeController::moveDiagonalLeft() 
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ThunderSnakeController::moveDiagonalRight() 
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
			currentPosition.x -= enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}
	}
}
