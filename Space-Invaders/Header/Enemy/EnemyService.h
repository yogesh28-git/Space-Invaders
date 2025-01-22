#pragma once

namespace Enemy {

	class EnemyController;

	class EnemyService {
	private:

		EnemyController* enemy;

		void destroy();

	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		EnemyController* spawnEnemy();
	};
}
