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
		b_reset = false;
	}

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
					if (isValidCollision(i, j)) collider_list[i]->onCollision(collider_list[j]);
					if (isValidCollision(i, j)) collider_list[j]->onCollision(collider_list[i]);
				}
			}
		}
	}

	bool CollisionService::isValidCollision(int index_i, int index_j)
	{
		return (index_i < collider_list.size() && index_j < collider_list.size() &&
			collider_list[index_i] != nullptr && collider_list[index_j] != nullptr);
	}

	void CollisionService::addCollider(ICollider* collider)
	{
		collider_list.push_back(collider);
	}

	void CollisionService::removeCollider(ICollider* collider)
	{
		collider_list.erase(std::remove(collider_list.begin(), collider_list.end(), collider), collider_list.end());
	}
}