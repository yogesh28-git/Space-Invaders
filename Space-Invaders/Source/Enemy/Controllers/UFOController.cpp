#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerup/PowerupConfig.h"

namespace Enemy
{
	namespace Controllers
	{
		using namespace Global;
		using namespace Powerup;

		void UFOController::move()
		{
			switch (enemy_model->getMovementDirection())
			{
			case MovementDirection::LEFT:
				moveLeft();
				break;
			case MovementDirection::RIGHT:
				moveRight();
				break;
			}
		}
		void UFOController::moveLeft()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x <= enemy_model->left_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}

			enemy_model->setEnemyPosition(current_position);
		}
		void UFOController::moveRight()
		{
			sf::Vector2f current_position = enemy_model->getEnemyPosition();
			current_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

			if (current_position.x >= enemy_model->right_most_position.x)
			{
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}

			enemy_model->setEnemyPosition(current_position);
		}
		Powerup::PowerupType UFOController::getRandomPowerup()
		{
			int index = std::rand() % 4;
			return static_cast<PowerupType>(index);
		}
		UFOController::UFOController(EnemyType type) : EnemyController(type)
		{
		}
		UFOController::~UFOController()
		{
		}
		void UFOController::fireBullet()
		{
		}
		void UFOController::initialize()
		{
			EnemyController::initialize();
		}
	}
}