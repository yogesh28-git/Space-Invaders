#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const float play_button_top_offset = 400.f;
			const float instructions_button_top_offset = 600.f;
			const float quit_button_top_offset = 800.f;

			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;

			// Textures:
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

			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButttons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			void processButtonInteractions();
			bool clickedButton(sf::Sprite*, sf::Vector2f);

		public:
			MainMenuUIController();

			void initialize();
			void update();
			void render();

			void show();
		};
	}
}