#pragma once
#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/UI/Interface/IUIController.h"

namespace UI
{
	class UIService
	{
	private:

		MainMenu::MainMenuController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();
		Interface::IUIController* getCurrentUIController();

	public:

		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		void showScreen();
	};
}