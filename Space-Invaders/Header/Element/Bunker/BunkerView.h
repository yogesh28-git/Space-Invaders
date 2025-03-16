#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Element
{
	namespace Bunker
	{
		class BunkerController;

		class BunkerView
		{
		private:

			const float bunker_sprite_width = 80.0f;
			const float bunker_sprite_height = 80.0f;

			UI::UIElement::ImageView* bunker_image;

			BunkerController* bunker_controller;

			void createUIElements();
			void initializeImage();
			sf::String getBunkerTexturePath();

		public:
			BunkerView();
			~BunkerView();

			void initialize(BunkerController* controller);
			void update();
			void render();

			const sf::Sprite& getBunkerSprite();
		};
	}
}