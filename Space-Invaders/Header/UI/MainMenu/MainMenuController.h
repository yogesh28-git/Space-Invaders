#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace MainMenu
	{
		class MainMenuController
		{
		private:

			const sf::String background_texture_path = "assets/textures/space_invaders_bg.png";
			const sf::String play_button_texture_path = "assets/textures/play_button.png";
			const sf::String instructions_button_texture_path = "assets/textures/instructions_button.png";
			const sf::String quit_button_texture_path = "assets/textures/quit_button.png";

			const float button_width = 400.0f;
			const float button_height = 140.0f;

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

			void initializeButtons();
			bool loadButtonTexturesFromFile();
			void setButtonSprites();

			void scaleAllButtons();
			void scaleButton(sf::Sprite& button_to_scale);
			void positionButtons();

			//Process Button Interactions
			void processButtonInteractions();
			bool clickedButton(sf::Sprite* sprite, sf::Vector2f position);

		public:

			MainMenuController();

			void initialize();
			void update();
			void render();
		};
	}
}