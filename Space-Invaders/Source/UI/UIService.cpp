#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace UI
{
	using namespace MainMenu;
	using namespace Main;
	using namespace Interface;
	using namespace UIElement;

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

	IUIController* UIService::getCurrentUIController()
	{
		switch (GameService::getGameState())
		{
		case GameState::BOOT:
			break;
		case GameState::MAIN_MENU:
			return main_menu_controller;
			break;
		default: 
			return nullptr;
			break;
		}
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


