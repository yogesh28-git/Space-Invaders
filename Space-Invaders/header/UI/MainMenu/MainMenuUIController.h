#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const sf::Color text_color = sf::Color::White;

			const float play_button_top_offset = 400.f;
			const float instructions_button_top_offset = 600.f;
			const float quit_button_top_offset = 800.f;

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float text_top_offset = 150.f;
			const int font_size = 80;

			bool mouse_button_pressed = false;

			sf::Font font;
			sf::Text high_score_text;
			sf::RenderWindow* game_window;

			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture play_button_texture;
			sf::Sprite play_button_sprite;

			sf::Texture instructions_button_texture;
			sf::Sprite instructions_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			void initializeBackgroundImage();
			void scaleBackgroundImage();

			void initializeTexts();
			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			bool pressedMouseButton();
			void handleButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

			void setTextPosition(float y_position);
			void updateHighScoreText();

		public:
			MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;

			void show() override;
		};
	}
}