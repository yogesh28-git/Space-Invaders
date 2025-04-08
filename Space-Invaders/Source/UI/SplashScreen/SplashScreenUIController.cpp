#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Sound/SoundService.h"

namespace UI
{
	namespace SplashScreen
	{
		using namespace UI::UIElement;
		using namespace Main;
		using namespace Global;
		using namespace Graphic;
		using namespace Sound;

		void SplashScreenUIController::initializeOutscalLogo()
		{
			sf::Vector2f position = getLogoPosition();
			outscal_logo_view->initialize(Config::outscal_logo_texture_path, logo_width, logo_height, position);
		}
		void SplashScreenUIController::fadeInAnimationCallback()
		{
			outscal_logo_view->playAnimation(AnimationType::FADE_OUT, splash_screen_duration, std::bind(&SplashScreenUIController::fadeOutAnimationCallback, this));
		}
		void SplashScreenUIController::fadeOutAnimationCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
			GameService::setGameState(GameState::MAIN_MENU);
		}
		sf::Vector2f SplashScreenUIController::getLogoPosition()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			
			float x_position = (game_window->getSize().x - logo_width) / 2.0f;
			float y_position = (game_window->getSize().y - logo_height) / 2.0f;

			return sf::Vector2f(x_position, y_position);
		}
		SplashScreenUIController::SplashScreenUIController()
		{
			outscal_logo_view = new AnimatedImageView();
		}
		SplashScreenUIController::~SplashScreenUIController()
		{
			delete outscal_logo_view;
		}
		void SplashScreenUIController::initialize()
		{
			initializeOutscalLogo();
		}
		void SplashScreenUIController::update()
		{
			outscal_logo_view->update();
		}
		void SplashScreenUIController::render()
		{
			outscal_logo_view->render();
		}
		void SplashScreenUIController::show()
		{
			outscal_logo_view->playAnimation(AnimationType::FADE_IN, splash_screen_duration, std::bind(&SplashScreenUIController::fadeInAnimationCallback, this));
		}
	}
}