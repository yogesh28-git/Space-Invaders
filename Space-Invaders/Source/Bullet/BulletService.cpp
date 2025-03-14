#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Collision/ICollider.h"

namespace Bullet
{
	using namespace Projectile;
	using namespace Controllers;
	using namespace Entity;
	using namespace Global;
	using namespace Collision;

	BulletController* BulletService::createBullet(BulletType type, EntityType owner_type)
	{

		switch (type)
		{
		case BulletType::LASER:
			return new LaserBulletController(type, owner_type);
			break;
		case BulletType::TORPEDO:
			return new TorpedoeController(type, owner_type);
			break;
		case BulletType::FROST:
			break;
		}
	}

	bool BulletService::isValidBullet(int index, std::vector<Projectile::IProjectile*>& bullet_list)
	{
		return index >= 0 && index < bullet_list.size() && bullet_list[index] != nullptr;
	}

	void BulletService::destroyFlaggedBullets()
	{
		for (int i = 0; i < flagged_bullet_list.size(); i++)
		{
			if (!isValidBullet(i, flagged_bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(flagged_bullet_list[i]));
			delete (flagged_bullet_list[i]);
		}
		flagged_bullet_list.clear();
	}

	void BulletService::destroy()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			if (!isValidBullet(i, bullet_list)) continue;

			ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(bullet_list[i]));
			delete (bullet_list[i]);
		}
		bullet_list.clear();
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
		bullet_list.clear();
		flagged_bullet_list.clear();
	}

	void BulletService::update()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			bullet_list[i]->update();
		}

		destroyFlaggedBullets();
	}

	void BulletService::render()
	{
		for (int i = 0; i < bullet_list.size(); i++)
		{
			bullet_list[i]->render();
		}
	}

	void BulletService::reset()
	{
		destroy();
	}

	BulletController* BulletService::spawnBullet(BulletType type, EntityType owner_type, sf::Vector2f position, MovementDirection direction)
	{
		BulletController* bullet_controller = createBullet(type, owner_type);
		bullet_controller->initialize(position, direction);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(bullet_controller));
		bullet_list.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::destroyBullet(BulletController* bullet_controller)
	{
		if (std::find(flagged_bullet_list.begin(), flagged_bullet_list.end(), bullet_controller) == flagged_bullet_list.end())
		{
			flagged_bullet_list.push_back(bullet_controller);
			bullet_list.erase(std::remove(bullet_list.begin(), bullet_list.end(), bullet_controller), bullet_list.end());
		}
	}

}