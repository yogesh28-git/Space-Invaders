#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Collision/ICollider.h"

namespace Enemy {
	
	class EnemyModel;
	class EnemyView;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController : public Collision::ICollider
	{

	protected:

		EnemyView* enemy_view;
		EnemyModel* enemy_model;

		float rate_of_fire = 3.0f;
		float elapsed_fire_duration = 0.0f;

		void updateFireTimer();
		void processBulletFire();
		virtual void fireBullet() = 0;

		virtual void move() = 0;

		sf::Vector2f getRandomInitialPosition();				//To spawn the enemy
		void handleOutOfBounds();								//So that enemy does not go out of screen bounds

	public:

		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void initialize();
		void update();
		void render();
		
		sf::Vector2f getEnemyPosition();
		EnemyType getEnemyType();
		EnemyState getEnemyState();
		sf::Vector2f getBarrelPositionOffset();

		const sf::Sprite& getColliderSprite() override;
		void onCollision(ICollider* other_collider) override;
	};
}
