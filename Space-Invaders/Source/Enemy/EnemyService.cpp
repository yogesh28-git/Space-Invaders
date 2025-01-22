#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"


namespace Enemy {
	void EnemyService::destroy()
	{
		delete(enemy);
		enemy = nullptr;
	}

	EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{
		enemy->update();
	}

	void EnemyService::render()
	{
		enemy->render();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		enemy = new EnemyController();
		enemy->initialize();

		return enemy;
	}

}

