#include "../../header/UI/UIService.h"
#include "../../header/Main/GameService.h"

namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace SplashScreen;
	using namespace Interface;
	using namespace GameplayUI;
	using namespace Instructions;
	using namespace Credits;

	UIService::UIService()
	{
		splash_screen_controller = nullptr;
		main_menu_controller = nullptr;
		gameplay_ui_controller = nullptr;
		instructions_ui_controller = nullptr;
		credits_ui_controller = nullptr;

		createControllers();
	}

	void UIService::createControllers()
	{
		splash_screen_controller = new SplashScreenUIController();
		main_menu_controller = new MainMenuUIController();
		gameplay_ui_controller = new GameplayUIController();
		instructions_ui_controller = new InstructionsScreenUIController();
		credits_ui_controller = new CreditsScreenUIController();
	}

	UIService::~UIService()
	{
		destroy();
	}

	void UIService::initialize()
	{
		initializeControllers();
	}

	void UIService::update()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			splash_screen_controller->update();
			break;

		case GameState::MAIN_MENU:
			return main_menu_controller->update();;
			break;
		}
	}

	void UIService::render()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			splash_screen_controller->render();
			break;

		case GameState::MAIN_MENU:
			return main_menu_controller->render();;
			break;
		}
	}

	void UIService::showScreen()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			splash_screen_controller->show();
			break;

		case GameState::MAIN_MENU:
			return main_menu_controller->show();;
			break;
		}
	}

	void UIService::initializeControllers()
	{
		splash_screen_controller->initialize();
		main_menu_controller->initialize();
		gameplay_ui_controller->initialize();
		instructions_ui_controller->initialize();
		credits_ui_controller->initialize();
	}

	void UIService::destroy()
	{
		delete(splash_screen_controller);
		delete(main_menu_controller);
		delete(gameplay_ui_controller);
		delete(instructions_ui_controller);
		delete(credits_ui_controller);
	}
}