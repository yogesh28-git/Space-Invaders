#include "../../header/Collision/CollisionService.h"
#include "../../header/Collision/ICollider.h"

namespace Collision
{
	CollisionService::CollisionService() { }

	CollisionService::~CollisionService() { }

	void CollisionService::initialize() { }

	void CollisionService::update()
	{
		processCollision();
	}

	void CollisionService::render() { }

	void CollisionService::processCollision()
	{
		for (int i = 0; i < collider_list.size(); i++)
		{
			for (int j = i + 1; j < collider_list.size(); j++)
			{
				const sf::Sprite& collider_one_sprite = collider_list[i]->getColliderSprite();
				const sf::Sprite& collider_two_sprite = collider_list[j]->getColliderSprite();

				if (collider_one_sprite.getGlobalBounds().intersects(collider_two_sprite.getGlobalBounds()))
				{
					collider_list[i]->onCollision(collider_list[j]);
					collider_list[j]->onCollision(collider_list[i]);
				}
			}
		}
	}

	void CollisionService::addCollider(ICollider* collider)
	{
		collider_list.push_back(collider);
	}

	void CollisionService::removeCollider(ICollider* collider)
	{
		// TODO
	}
}