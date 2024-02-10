#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const sf::Color text_color = sf::Color::White;
			const float background_alpha = 85.f;

			const float play_button_top_offset = 400.f;
			const float instructions_button_top_offset = 600.f;
			const float quit_button_top_offset = 800.f;

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float text_top_offset = 150.f;
			const int font_size = 80;

			sf::Text high_score_text;

			UIElement::ImageView* background_image;

			UIElement::ButtonView* play_button;
			UIElement::ButtonView* instructions_button;
			UIElement::ButtonView* quit_button;

			void createImage();
			void createButtons();

			void initializeBackgroundImage();
			void initializeTexts();
			void initializeButtons();

			void registerButtonCallback();
			void playButtonCallback();
			void instructionsButtonCallback();
			void quitButtonCallback();

			void destroy();

			void setTextPosition(float y_position);
			void updateHighScoreText();

		public:
			MainMenuUIController();
			~MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}