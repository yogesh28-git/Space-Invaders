#pragma once
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Projectile/IProjectile.h"

namespace Bullet
{
	class BulletModel;
	class BulletView;
	enum class BulletType;

	class BulletController : public Projectile::IProjectile
	{
	protected: 

		BulletModel* bullet_model;
		BulletView* bullet_view;

		void updateProjectilePosition() override;


		void moveUp();
		void moveDown();
		void handleOutOfBounds();

	public:
		BulletController(BulletType type);
		virtual ~BulletController() override;

		void initialize(sf::Vector2f position, MovementDirection direction) override;
		void update() override;
		void render() override;
		
		sf::Vector2f getProjectilePosition() override;
		BulletType getBulletType();
	};
}
