#include "../../header/Enemy/EnemyService.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Time/TimeService.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../header/Enemy/Controller/ZapperController.h"
#include "../../header/Enemy/Controller/ThunderSnakeController.h"
#include "../../header/Enemy/Controller/SubzeroController.h"
#include "../../header/Enemy/Controller/UFOController.h"

namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService() { std::srand(static_cast<unsigned>(std::time(nullptr))); }

	EnemyService::~EnemyService() { destroy(); }

	void EnemyService::initialize() 
	{
		spawn_timer = spawn_interval;
	}

	void EnemyService::update()
	{
		updateSpawnTimer();
		processEnemySpawn();

		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->update();
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++) enemy_list[i]->render();
	}

	void EnemyService::updateSpawnTimer()
	{
		spawn_timer += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	void EnemyService::processEnemySpawn()
	{
		if (spawn_timer >= spawn_interval)
		{
			spawnEnemy();
			spawn_timer = 0.0f;
		}
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
		enemy_controller->initialize();

		enemy_list.push_back(enemy_controller);
		return enemy_controller;
	}

	EnemyType EnemyService::getRandomEnemyType()
	{
		int random_value = std::rand() % (static_cast<int>(Enemy::EnemyType::UFO) + 1);
		return static_cast<Enemy::EnemyType>(random_value);
	}

	EnemyController* EnemyService::createEnemy(EnemyType enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case::Enemy::EnemyType::SUBZERO:
			return new SubzeroController(Enemy::EnemyType::SUBZERO);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		delete(enemy_controller);
	}

	void EnemyService::destroy()
	{
		for (int i = 0; i < enemy_list.size(); i++) delete (enemy_list[i]);
	}
}