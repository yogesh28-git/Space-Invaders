#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
	using namespace MainMenu;
	using namespace Main;

	void UI::UIService::createControllers()
	{
		main_menu_controller = new MainMenuController();
	}

	void UI::UIService::initializeControllers()
	{
		main_menu_controller->initialize();
	}

	void UI::UIService::destroy()
	{
		delete main_menu_controller;
		main_menu_controller = nullptr;

	}

	UI::UIService::UIService()
	{
		main_menu_controller = nullptr;

		createControllers();
	}

	UI::UIService::~UIService()
	{
		destroy();
	}

	void UI::UIService::initialize()
	{
		initializeControllers();
	}

	void UI::UIService::update()
	{
		switch (GameService::getGameState()) 
		{
			case GameState::MAIN_MENU:
				main_menu_controller->update();
				break;
		}
		
	}

	void UI::UIService::render()
	{
		switch (GameService::getGameState())
		{
			case GameState::MAIN_MENU:
				main_menu_controller->render();
				break;
		}
	}
}


