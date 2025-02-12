#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"

#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"


namespace Enemy {

	using namespace Global;
	using namespace Controllers;

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

	EnemyType EnemyService::getRandomEnemyType()
	{
		int rand_type = std::rand() % 3;
		return static_cast<EnemyType> (rand_type);
	}

	EnemyController* EnemyService::createEnemy(EnemyType type)
	{
		switch (type)
		{
		case EnemyType::ZAPPER:
			return new ZapperController(type);
			break;
		
		case EnemyType::SUBZERO:
			return new SubZeroController(type);
			break;
		
		case EnemyType::UFO:
			return new UFOController(type);
			break;

		default: 
			return new ZapperController(type);
			break;
		}
	}

	EnemyService::EnemyService()
	{
		for (EnemyController* enemy : enemy_list)
			enemy = nullptr;

		std::srand(static_cast<unsigned>(std::time(nullptr)));
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
		EnemyController* enemy = createEnemy(getRandomEnemyType());
		enemy->initialize();

		enemy_list.push_back(enemy);
	}

	void EnemyService::destroyEnemy(EnemyController* controller)
	{
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), controller), enemy_list.end());

		delete controller;
	}

}

