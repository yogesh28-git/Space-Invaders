#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Global
{
	using namespace Main;
	using namespace Event;
	using namespace UI;
	using namespace Player;
	using namespace Time;
	using namespace Sound;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		sound_service = nullptr;
		event_service = nullptr;
		player_service = nullptr;
		ui_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		time_service = new TimeService();
		sound_service = new SoundService();
		event_service = new EventService();
		player_service = new PlayerService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		player_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY) player_service->update();

		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		
		if (GameService::getGameState() == GameState::GAMEPLAY) player_service->render();

		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(player_service);
		delete(event_service);
		delete(graphic_service);
		delete(sound_service);
		delete(time_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	Player::PlayerService* ServiceLocator::getPlayerService() { return player_service; }

	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	Sound::SoundService* ServiceLocator::getSoundService() { return sound_service; }

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}