#pragma once
#include <SFML/Graphics.hpp>

namespace Collision
{
	enum class CollisionState
	{
		ENABLED,
		DISABLED
	};

	class ICollider
	{
	private:
		CollisionState collision_state;

	public:
		ICollider();
		virtual ~ICollider();

		virtual const sf::Sprite& getColliderSprite() = 0;
		virtual void onCollision(ICollider* other_collider) = 0;

		CollisionState getCollisionState();
		void enableCollision();
		void disableCollision();
	};
}