#pragma once
#include "SFML/Graphics.hpp"
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float font_size = 40.f;

			const float text_y_position = 15.f;
			const float enemies_killed_text_x_position = 1530.f;
			const float score_text_x_position = 870.f;
			const float bullets_fired_text_x_position = 60.f;

			const sf::Color text_color = sf::Color::White;

			sf::Font font;
			sf::Text score_text;
			sf::Text enemies_killed_text;
			sf::Text bullets_fired_text;

			void initializeTexts();
			void initializeText(sf::Text& text, sf::String initial_text, sf::Vector2f position);
			void updateScoreText();
			void updateEnemiesKilledText();
			void updateBulletsFiredText();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}