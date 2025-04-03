#pragma once
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/UIElement/ButtonView.h"
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/TextView.h"


namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:

			//Constants
			
			const float font_size = 40.0f;
			const float enemies_killed_text_y_position = 15.0f;
			const float enemies_killed_text_x_position = 60.0f;

			const sf::Color text_color = sf::Color::White;

			const float player_lives_y_offset = 25.0f;
			const float player_lives_x_offset = 1850.0f;
			const float player_lives_spacing = 60.0f;

			const float player_sprite_width = 30.0f;
			const float player_sprite_height = 30.0f;

			UI::UIElement::ImageView* player_image;
			UI::UIElement::TextView* enemies_killed_text;

			void createUIElements();
			void initializeImage();
			void initializeText();
			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
			
			void updateEnemiesKilledText();
			void drawPlayerLives();
		};
	}
}

