#include "../../Header/UI/UIService.h"

namespace UI
{
	using namespace MainMenu;

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
		main_menu_controller->update();
	}

	void UI::UIService::render()
	{
		main_menu_controller->render();
	}
}


