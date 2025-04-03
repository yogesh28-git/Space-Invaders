#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"
#include "../../Header/UI/Interface/IUIController.h"
#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUI.h"

namespace UI
{
	using namespace MainMenu;
	using namespace Main;
	using namespace Interface;
	using namespace UIElement;
	using namespace SplashScreen;
	using namespace GameplayUI;

	void UI::UIService::createControllers()
	{
		main_menu_ui_controller = new MainMenuController();
		gameplay_ui_controller = new GameplayUIController();
		splash_screen_ui_controller = new SplashScreenUIController();
	}

	void UI::UIService::initializeControllers()
	{
		main_menu_ui_controller->initialize();
		gameplay_ui_controller->initialize();
		splash_screen_ui_controller->initialize();
	}

	void UI::UIService::destroy()
	{
		delete main_menu_ui_controller;
		delete gameplay_ui_controller;
		delete splash_screen_ui_controller;
	}

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splash_screen_ui_controller;
			break;
		case GameState::MAIN_MENU:
			return main_menu_ui_controller;
			break;
		case GameState::GAMEPLAY:
			return gameplay_ui_controller;
		default: 
			return nullptr;
			break;
		}
	}

	UI::UIService::UIService()
	{
		main_menu_ui_controller = nullptr;
		gameplay_ui_controller = nullptr;
		splash_screen_ui_controller = nullptr;

		createControllers();
	}

	UI::UIService::~UIService()
	{
		destroy();
	}

	void UI::UIService::initialize()
	{
		TextView::initializeTextView();
		initializeControllers();
	}

	void UI::UIService::update()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
			ui_controller->update();
		
	}

	void UI::UIService::render()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller) 
			ui_controller->render();
	}
	void UIService::showScreen()
	{
		IUIController* ui_controller = getCurrentUIController();
		if (ui_controller)
			ui_controller->show();
	}
}


