#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace Credits
	{
		class CreditsScreenUIController
		{
		private:
			const sf::String game_title = "Outscal Presents - Space Invaders";

			const float text_top_offset = 200.f;
			const int font_size = 80;

			const float menu_button_top_offset = 500.f;
			const float quit_button_top_offset = 700.f;
			const sf::Color text_color = sf::Color::White;

			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;

			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture menu_button_texture;
			sf::Sprite menu_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			sf::Font font;
			sf::Text game_title_text;

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

		public:
			void initialize();
			void update();
			void render();
			void show();
		};
	}
}