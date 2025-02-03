#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global
{
	using namespace Graphic;
	using namespace Event;
	using namespace Time;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		ui_service = nullptr;
		enemy_service = nullptr;
		gameplay_service = nullptr;
		element_service = nullptr;
		sound_service = nullptr;
		createServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		time_service = new TimeService();
		event_service = new EventService();
		player_service = new PlayerService();
		ui_service = new UIService();
		enemy_service = new EnemyService();
		gameplay_service = new GameplayService();
		element_service = new ElementService();
		sound_service = new SoundService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete graphic_service;
		graphic_service = nullptr;

		delete time_service;
		time_service = nullptr;

		delete event_service;
		event_service = nullptr;

		delete player_service;
		player_service = nullptr;

		delete ui_service;
		ui_service = nullptr;

		delete enemy_service;
		enemy_service = nullptr;

		delete gameplay_service;
		gameplay_service = nullptr;

		delete element_service;
		element_service = nullptr;

		delete sound_service;
		sound_service = nullptr;
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		event_service->initialize();
		gameplay_service->initialize();
		player_service->initialize();
		ui_service->initialize();
		enemy_service->initialize();
		element_service->initialize();
		sound_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();
		ui_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
			element_service->update();
		}
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		ui_service->render();

		if (GameService::getGameState() == GameState::GAMEPLAY) {
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			element_service->render();
		}
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}

	UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}

	EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}

	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	Element::ElementService* ServiceLocator::getElementService()
	{
		return element_service;
	}

	Sound::SoundService* ServiceLocator::getSoundService()
	{
		return sound_service;
	}



}

