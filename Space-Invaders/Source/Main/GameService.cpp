#include "../../Header/Main/GameService.h"

namespace Main
{
	using namespace Global;

	// PRIVATE METHODS //

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
	}

	void GameService::destroy()
	{
		//cleanup resources
	}

	// PUBLIC METHODS //

	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::ignite()
	{
		service_locator = ServiceLocator::getInstance();
		initialize();
	}

	void GameService::update()
	{
		// Check for events
		service_locator->getEventService()->processEvents();

		// Perform state updates
		service_locator->update();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}

}

