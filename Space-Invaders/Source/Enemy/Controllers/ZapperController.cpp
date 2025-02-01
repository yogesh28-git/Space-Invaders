#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy {

	namespace Controllers {

		using namespace Global;

		void ZapperController::move()
		{
			switch (enemy_model->getMovementDirection()) {
			case MovementDirection::LEFT:
				moveLeft();
				break;

			case MovementDirection::RIGHT:
				moveRight();
				break;

			case MovementDirection::DOWN:
				moveDown();
				break;
			}
		}
		void ZapperController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x) {
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(current_position);
			}

			enemy_model->setEnemyPosition(current_position);
			
		}
		void ZapperController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x) {
				enemy_model->setMovementDirection(MovementDirection::DOWN);
				enemy_model->setReferencePosition(current_position);
			}

			enemy_model->setEnemyPosition(current_position);
			
		}
		void ZapperController::moveDown()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.y - enemy_model->getReferencePosition().y >= vertical_travel_distance) {
				// On the left side, need to go right
				if (current_position.x <= enemy_model->left_most_position.x) {
					enemy_model->setMovementDirection(MovementDirection::RIGHT);
				}
				else {
					enemy_model->setMovementDirection(MovementDirection::LEFT);
				}
			}

			enemy_model->setEnemyPosition(current_position);
			
		}
		ZapperController::ZapperController(EnemyType type) : EnemyController(type)
		{
		}
		ZapperController::~ZapperController()
		{
		}
		void ZapperController::initialize()
		{
			EnemyController::initialize();
		}
	}
}