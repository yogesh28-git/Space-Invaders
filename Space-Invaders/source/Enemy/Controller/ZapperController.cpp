#include "../../header/Enemy/Controller/ZapperController.h"
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
		ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

		ZapperController::~ZapperController() { }

		void ZapperController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setEnemyPosition(initial_position);
		}

		void ZapperController::moveLeft()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x -= enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x <= left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveRight()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.x += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.x >= right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(currentPosition);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (currentPosition.y >= enemy_model->getReferencePosition().y + vertical_travel_distance)
			{
				if (enemy_model->getReferencePosition().x <= left_most_position.x) enemy_model->setMovementDirection(MovementDirection::RIGHT);
				else enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
			else enemy_model->setEnemyPosition(currentPosition);
		}

		void ZapperController::moveDiagonalLeft() { }

		void ZapperController::moveDiagonalRight() { }
	}
}
