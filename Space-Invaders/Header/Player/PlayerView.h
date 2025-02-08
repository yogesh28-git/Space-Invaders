#pragma once
#include <SFML/Graphics.hpp>


namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:

		const float player_sprite_width = 60.0f;
		const float player_sprite_height = 60.0f;
		const sf::Vector2f barrel_position_offset = sf::Vector2f(30.0f, 0.0f);

		sf::RenderWindow* game_window;
		PlayerController* player_controller;

		sf::Texture player_texture;
		sf::Sprite player_sprite;

		void initializePlayerSprite();
		void scalePlayerSprite();

	public:

		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

		sf::Vector2f getBarrelPositionOffset();
	};

}

