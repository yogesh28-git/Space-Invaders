#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerup/PowerupConfig.h"

namespace Enemy
{
	namespace Controllers
	{
		class UFOController : public EnemyController
		{
		private:

			void move() override;
			void moveLeft();
			void moveRight();
			Powerup::PowerupType getRandomPowerup();

		public:

			UFOController(EnemyType type);
			~UFOController() override;

			void fireBullet() override;

			void initialize() override;
		};
	}
}
