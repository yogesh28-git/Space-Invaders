#pragma once

#include <SFML/Graphics.hpp>
#include "../../Header/Global/ServiceLocator.h"


namespace Main
{

	enum class GameState
	{
		BOOT,
		SPLASH_SCREEN,
		MAIN_MENU,
		INSTRUCTIONS,
		GAMEPLAY,
		CREDITS,
	};

	class GameService
	{
	private:

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		static GameState current_state;

		void initialize();
		void initializeVariables();
		void destroy();

		void showSplashScreen();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();

		static void setGameState(GameState state);
		static GameState getGameState();
	};

}

