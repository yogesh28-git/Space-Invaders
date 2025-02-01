#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {
	
	class EnemyModel;
	class EnemyView;
	enum class EnemyState;
	enum class EnemyType;

	class EnemyController {

	protected:

		EnemyView* enemy_view;
		EnemyModel* enemy_model;

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
	};
}
