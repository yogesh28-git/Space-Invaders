#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Global/ServiceLocator.h"

namespace Main
{
	class GameService
	{
	private:
		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void destroy();

	public:
		GameService();
		virtual ~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();
	};
}