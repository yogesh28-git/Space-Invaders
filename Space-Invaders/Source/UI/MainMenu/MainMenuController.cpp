#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/Config.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Event;
		using namespace Sound;
		using namespace UI::UIElement;

		void MainMenuController::createImage()
		{
		}

		void MainMenuController::createButtons()
		{
			play_button = new ButtonView();
			instructions_button = new ButtonView();
			quit_button = new ButtonView();
		}

		void MainMenuController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void MainMenuController::initializeButtons()
		{
			play_button->initialize("Play Button", Config::play_button_texture_path, button_width, button_height, sf::Vector2f(0, play_button_y_position));
			instructions_button->initialize("Instructions Button", Config::instructions_button_texture_path, button_width, button_height, sf::Vector2f(0, instructions_button_y_position));
			quit_button->initialize("Quit Button", Config::quit_button_texture_path, button_width, button_height, sf::Vector2f(0, quit_button_y_position));

			play_button->setCentreAligned();
			instructions_button->setCentreAligned();
			quit_button->setCentreAligned();
		}
		void MainMenuController::registerButtonCallback()
		{
			play_button->registerCallbackFunction(std::bind(&MainMenuController::playButtonCallback, this));
			instructions_button->registerCallbackFunction(std::bind(&MainMenuController::instructionsButtonCallback, this));
			quit_button->registerCallbackFunction(std::bind(&MainMenuController::quitButtonCallback, this));
		}
		void MainMenuController::playButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
		}
		void MainMenuController::instructionsButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
		}
		void MainMenuController::quitButtonCallback()
		{
			ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->close();
		}

		void MainMenuController::destroy()
		{
			delete (play_button);
			delete (instructions_button);
			delete (quit_button);
			delete (background_image);
		}

		MainMenuController::MainMenuController()
		{
		}
		MainMenuController::~MainMenuController()
		{
		}
		void MainMenuController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}
		void MainMenuController::update()
		{
			background_image->update();
			play_button->update();
			instructions_button->update();
			quit_button->update();
		}
		void MainMenuController::render()
		{
			background_image->render();
			play_button->render();
			instructions_button->render();
			quit_button->render();
		}
		void MainMenuController::show()
		{
			background_image->show();
			play_button->show();
			instructions_button->show();
			quit_button->show();

			ServiceLocator::getInstance()->getSoundService()->playBackgroundMusic();
		}
	}
}