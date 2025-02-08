#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy {

	class EnemyController;
	enum class EnemyType;

	class EnemyView {
	private:
		
		const float enemy_sprite_width = 60.0f;
		const float enemy_sprite_height = 60.0f;
		const sf::Vector2f barrel_position_offset = sf::Vector2f(30.0f, 60.0f);

		EnemyController* enemy_controller;

		sf::RenderWindow* game_window;

		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		void initializeEnemySprite(EnemyType enemy_type);
		void scaleEnemySprite();


	public:
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);

		void update();
		void render();

		sf::Vector2f getBarrelPositionOffset();
	};
}
