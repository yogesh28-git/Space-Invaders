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
	using namespace Collision;

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
	void EnemyService::destroyFlaggedEnemies()
	{
		for (int i = 0; i < flagged_enemy_list.size(); i++)
		{
			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_enemy_list[i]));
			delete (flagged_enemy_list[i]);
		}
		flagged_enemy_list.clear();
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

		destroyFlaggedEnemies();
	}

	void EnemyService::render()
	{
		for (EnemyController* enemy : enemy_list)
			enemy->render();
	}

	void EnemyService::reset()
	{
		spawn_timer = spawn_interval;
		for (EnemyController* enemy : enemy_list)
			delete enemy;
		enemy_list.clear();
	}

	void EnemyService::spawnEnemy()
	{
		EnemyController* enemy = createEnemy(getRandomEnemyType());
		enemy->initialize();

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(enemy));
		enemy_list.push_back(enemy);
	}

	void EnemyService::destroyEnemy(EnemyController* controller)
	{
		if (std::find(flagged_enemy_list.begin(), flagged_enemy_list.end(), controller) == flagged_enemy_list.end())
		{
			dynamic_cast<ICollider*>(controller)->disableCollision();
			flagged_enemy_list.push_back(controller);
			enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), controller), enemy_list.end());
		}
	}

}

