#pragma once
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/UI/SplashScreen/SplashScreenUIController.h"

namespace UI
{
	class UIService
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();
		void showScreen();
	};
}