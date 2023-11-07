#pragma once
#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/UI/SplashScreen/SplashScreenUIController.h"

class UIService
{
private:
	SplashScreenUIController* splash_screen_controller;
	MainMenuUIController* main_menu_controller;

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