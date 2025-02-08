#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy {

	namespace Controllers {

		class SubZeroController : public EnemyController {

		private:
			float vertical_movement_speed = 100.0f;
			float subzero_rate_of_fire = 4.0f;

			void move() override;
			void moveDown();

		public:
			SubZeroController(EnemyType type);
			~SubZeroController() override;

			void fireBullet() override;

			void initialize() override;
		};
	}
}
