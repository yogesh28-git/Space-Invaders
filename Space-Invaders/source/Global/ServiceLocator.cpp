#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

namespace Global
{
	using namespace Main;
	using namespace Event;
	using namespace UI;
	using namespace Time;
	using namespace Sound;
	using namespace Gameplay;
	using namespace Player;
	using namespace Enemy;
	using namespace Element;
	using namespace Bullet;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		time_service = nullptr;
		sound_service = nullptr;
		event_service = nullptr;
		gameplay_service = nullptr;
		player_service = nullptr;
		enemy_service = nullptr;
		element_service = nullptr;
		bullet_service = nullptr;
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
		gameplay_service = new GameplayService();
		player_service = new PlayerService();
		enemy_service = new EnemyService();
		element_service = new ElementService();
		bullet_service = new BulletService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		gameplay_service->initialize();
		player_service->initialize();
		enemy_service->initialize();
		element_service->initialize();
		bullet_service->initialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		time_service->update();
		event_service->update();

		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->update();
			player_service->update();
			enemy_service->update();
			element_service->update();
			bullet_service->update();
		}

		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			gameplay_service->render();
			player_service->render();
			enemy_service->render();
			element_service->render();
			bullet_service->render();
		}

		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(bullet_service);
		delete(player_service);
		delete(enemy_service);
		delete(gameplay_service);
		delete(element_service);
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

	Enemy::EnemyService* ServiceLocator::getEnemyService() { return enemy_service; }

	Element::ElementService* ServiceLocator::getElementService() { return element_service; }

	Bullet::BulletService* ServiceLocator::getBulletService() { return bullet_service; }

	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	Sound::SoundService* ServiceLocator::getSoundService() { return sound_service; }

	Gameplay::GameplayService* ServiceLocator::getGameplayService() { return gameplay_service; }

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}