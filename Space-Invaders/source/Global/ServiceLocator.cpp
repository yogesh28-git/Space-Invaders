#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"



namespace Global
{
	using namespace Graphics;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Element;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;
	using namespace Sound;
	using namespace Collision;
	

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
		bullet_service = nullptr;
		powerup_service = nullptr;
		collision_service = nullptr;
		
		ui_service = nullptr;
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
		bullet_service = new BulletService();
		powerup_service = new PowerupService();
		collision_service = new CollisionService();

		ui_service = new UIService();
		sound_service = new SoundService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		time_service->initialize();
		event_service->initialize();
		gameplay_service->initialize();
		player_service->initialize();
		enemy_service->initialize();
		element_service->initialize();
		bullet_service->initialize();
		powerup_service->initialize();
		collision_service->initialize();
		
		ui_service->initialize();
		sound_service->initialize();
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
			powerup_service->update();
			collision_service->update();
			
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
			powerup_service->render();
		
		}

		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(time_service);
		delete(event_service);
		delete(player_service);
		delete(ui_service);
		delete(enemy_service);
		delete(gameplay_service);
		delete(element_service);
		delete(bullet_service);
		delete(sound_service);
		delete(collision_service);
		delete(powerup_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}


	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }
	EventService* ServiceLocator::getEventService() { return event_service; }
	PlayerService* ServiceLocator::getPlayerService() { return player_service; }
	
	UIService* ServiceLocator::getUIService() { return ui_service; }
	EnemyService* ServiceLocator::getEnemyService() { return enemy_service; }
	
	Collision::CollisionService* ServiceLocator::getCollisionService() { return collision_service; }

	



	Element::ElementService* ServiceLocator::getElementService() { return element_service; }

	Bullet::BulletService* ServiceLocator::getBulletService() { return bullet_service; }

	Powerup::PowerupService* ServiceLocator::getPowerupService() { return powerup_service; }

	



	Time::TimeService* ServiceLocator::getTimeService() { return time_service; }

	Gameplay::GameplayService* ServiceLocator::getGameplayService() { return gameplay_service; }

	Sound::SoundService* ServiceLocator::getSoundService() { return sound_service; }

	
}
