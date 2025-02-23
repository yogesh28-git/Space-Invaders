#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:

		const float player_sprite_width = 60.0f;
		const float player_sprite_height = 60.0f;
		const sf::Vector2f barrel_position_offset = sf::Vector2f(30.0f, 0.0f);

		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		void createUIElements();
		void initializeImage();
		sf::String getPlayerTexturePath();
		void destroy();

	public:

		PlayerView();
		~PlayerView();

		void initialize(PlayerController* controller);
		void update();
		void render();

		sf::Vector2f getBarrelPositionOffset();
	};

}

