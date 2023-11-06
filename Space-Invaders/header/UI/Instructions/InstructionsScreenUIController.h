#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
	namespace Instructions
	{
		class InstructionsScreenUIController : public Interface::IUIController
		{
		private:
			static const int number_of_instructions = 4;
			const float text_top_offset = 200.f;
			const float text_spacing = 95.f;
			const int font_size = 50;

			const float menu_button_top_offset = 700.f;
			const sf::Color text_color = sf::Color::White;

			sf::String instructions[number_of_instructions] = { "Use the arrow keys to 'Move' your 'Spaceship'",
																"Press the 'Left Mouse Button' to fire lasers and destroy the 'Alien' invaders",
																"Collect 'Power-ups' for improved 'Firepower' and 'Shields'",
																"Compete for the 'High Score'"};


			// Constants:
			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;

			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture menu_button_texture;
			sf::Sprite menu_button_sprite;

			sf::Font font;
			sf::Text instructions_text;

			void initializeBackgroundImage();
			void scaleBackgroundImage();

			void initializeTexts();

			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			void handleButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

			void setTextPosition(float y_position);
			void drawInstructions();

		public:

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}