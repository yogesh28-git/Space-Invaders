#pragma once
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/UI/Instructions/InstructionsScreenUIController.h"
#include "../../header/UI/Credits/CreditsScreenUIController.h"

namespace UI
{
	class UIService
	{
	private:
		SplashScreen::SplashScreenUIController* splash_screen_controller;
		MainMenu::MainMenuUIController* main_menu_controller;
		GameplayUI::GameplayUIController* gameplay_ui_controller;
		Instructions::InstructionsScreenUIController* instructions_ui_controller;
		Credits::CreditsScreenUIController* credits_ui_controller;

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