#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {

	namespace Controllers {

		using namespace Global;

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
		void SubZeroController::initialize()
		{
			EnemyController::initialize();
			enemy_model->setMovementDirection(MovementDirection::DOWN);
		}
	}
}