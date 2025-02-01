#pragma once
#include <vector>

namespace Enemy {

	class EnemyController;
	enum class EnemyType;

	class EnemyService {
	private:

		std::vector<EnemyController*> enemy_list;

		const float spawn_interval = 3.0f;
		float spawn_timer;

		void updateSpawnTimer();
		void processEnemySpawn();
		void destroy();
		EnemyType getRandomEnemyType();
		EnemyController* createEnemy(EnemyType type);

	public:
		EnemyService();
		~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy();
		void destroyEnemy(EnemyController* controller);
	};
}
