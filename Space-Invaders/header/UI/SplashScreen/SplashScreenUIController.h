#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/Interface/IUIController.h"

namespace UI
{
	namespace SplashScreen
	{
		class SplashScreenUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float logo_animation_time = 2.0f;
			const float splash_screen_time = 4.0f;

			sf::RenderWindow* game_window;
			sf::Texture outscal_logo_texture;
			sf::Sprite outscal_logo_sprite;
			sf::Clock clock;
			float elapsed_time;

			// Initialization:
			void initializeVariables();
			void initializeOutscalLogo();
			void loadOutscalTexture();
			bool tryLoadingOutscalLogo();
			void setPositionToCenter();

			void showLogoWithFade();
			void hideLogoWithFade();
			void logoAnimationComplete();
			void updateLogo(float deltaTime);

		public:
			SplashScreenUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}