#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy {

	using namespace Global;

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}
	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer > spawn_interval) {
			spawnEnemy();
			spawn_timer = 0.0f;
		}
	}
	void EnemyService::destroy()
	{
		for (EnemyController* enemy : enemy_list) {
			delete(enemy);
			enemy = nullptr;
		}
			
	}

	EnemyService::EnemyService()
	{
		for (EnemyController* enemy : enemy_list)
			enemy = nullptr;
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawn_timer = spawn_interval; // for the first spawn.
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (EnemyController* enemy : enemy_list)
			enemy->update();
	}

	void EnemyService::render()
	{
		for (EnemyController* enemy : enemy_list)
			enemy->render();
	}

	void EnemyService::spawnEnemy()
	{
		EnemyController* enemy = new EnemyController();
		enemy->initialize();

		enemy_list.push_back(enemy);
	}

}

