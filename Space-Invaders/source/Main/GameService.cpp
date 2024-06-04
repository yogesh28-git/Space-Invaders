#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"



namespace Main
{
	using namespace Global;

	GameState GameService::current_state = GameState::BOOT;

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showMainMenu();

	}

	

	void GameService::showMainMenu()
	{
		setGameState(GameState::MAIN_MENU);
		//ServiceLocator::getInstance()->getUIService()->showScreen();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}



	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameService::update()
	{
		// Process Events.
		service_locator->getEventService()->processEvents();


		// Update Game Logic.
		service_locator->update();
	}

	void GameService::render()
	{

		game_window->clear();
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

	void GameService::setGameState(GameState new_state) { current_state = new_state; }

	GameState GameService::getGameState() { return current_state; }
}


