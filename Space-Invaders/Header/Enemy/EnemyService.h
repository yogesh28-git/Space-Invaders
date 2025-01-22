#pragma once
#include <vector>

namespace Enemy {

	class EnemyController;

	class EnemyService {
	private:

		std::vector<EnemyController*> enemy_list;

		const float spawn_interval = 3.0f;
		float spawn_timer;

		void updateSpawnTimer();
		void processEnemySpawn();
		void destroy();

	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy();
	};
}
