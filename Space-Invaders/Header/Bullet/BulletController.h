#pragma once
#include <SFML/System/Vector2.hpp>
#include "../../Header/Projectile/IProjectile.h"
#include "../../Header/Entity/EntityConfig.h"
#include "../../Header/Collision/ICollider.h"

namespace Bullet
{
	class BulletModel;
	class BulletView;
	enum class BulletType;
	enum class MovementDirection;

	class BulletController : public Projectile::IProjectile, public Collision::ICollider
	{
	protected: 

		BulletModel* bullet_model;
		BulletView* bullet_view;

		void updateProjectilePosition() override;

		void moveUp();
		void moveDown();
		void handleOutOfBounds();

	public:

		BulletController(BulletType type, Entity::EntityType owner_type);
		virtual ~BulletController() override;

		virtual void initialize(sf::Vector2f position, MovementDirection direction) override;
		void update() override;
		void render() override;
		
		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();

		Entity::EntityType getOwnerEntityType();

		void processBulletCollision(ICollider* other_collider);
		void processEnemyCollision(ICollider* other_collider);
		void processPlayerCollision(ICollider* other_collider);
		void processBunkerCollision(ICollider* other_collider);

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}
