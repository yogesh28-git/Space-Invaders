#pragma once
#include "../../Header/Enemy/EnemyController.h"

namespace Enemy {

	namespace Controllers {

		class ZapperController : public EnemyController {

		private:

			float vertical_travel_distance = 100.0f;

			void move() override;
			void moveLeft();
			void moveRight();
			void moveDown();

		public:
			ZapperController(EnemyType type);
			~ZapperController() override;

			void initialize() override;
		};
	}
}
