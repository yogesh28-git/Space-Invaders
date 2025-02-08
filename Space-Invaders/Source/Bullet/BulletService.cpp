#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"


namespace Bullet
{
	using namespace Projectile;
	using namespace Controllers;

	BulletController* BulletService::createBullet(BulletType type)
	{

		switch (type)
		{
		case BulletType::LASER:
			return new LaserBulletController(type);
			break;
		case BulletType::TORPEDO:
			return new TorpedoeController(type);
			break;
		case BulletType::FROST:
			break;
		}
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			delete bullet_list[i];
		}
	}

	BulletService::BulletService()
	{
	}

	BulletService::~BulletService()
	{
		destroy();
	}

	void BulletService::initialize()
	{
	}

	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			bullet_list[i]->update();
		}
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			bullet_list[i]->render();
		}
	}

	BulletController* BulletService::spawnBullet(BulletType type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* controller = createBullet(type);
		controller->initialize(position, direction);

		bullet_list.push_back(controller);
		return controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());

		delete bullet_controller;
	}

}