#include "../../header/Enemy/Controller/SubzeroController.h"
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
		SubzeroController::SubzeroController(EnemyType type) : EnemyController(type) { }

		SubzeroController::~SubzeroController() { }

		void SubzeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setEnemyPosition(initial_position);
			enemy_model->setMovementDirection(MovementDirection::DOWN);
		}

		void SubzeroController::moveLeft() { }

		void SubzeroController::moveRight() { }

		void SubzeroController::moveDown()
		{
			sf::Vector2f currentPosition = enemy_model->getEnemyPosition();
			currentPosition.y += enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			enemy_model->setEnemyPosition(currentPosition);
		}

		void SubzeroController::moveDiagonalLeft() { }

		void SubzeroController::moveDiagonalRight() { }
	}
}
