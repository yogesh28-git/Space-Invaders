#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerup/Controllers/OutscalBombController.h"
#include "../../Header/Powerup/Controllers/RapidFireController.h"
#include "../../Header/Powerup/Controllers/ShieldController.h"
#include "../../Header/Powerup/Controllers/TrippleLaserController.h"

namespace Powerup
{
	using namespace Controllers;
	using namespace Global;
	using namespace Collision;

	PowerupController* PowerupService::createPowerup(PowerupType type)
	{
		switch (type)
		{
		case PowerupType::BOMB:
			return new OutscalBombController(type);
			break;
		case PowerupType::RAPID_FIRE:
			return new RapidFireController(type);
			break;
		case PowerupType::SHIELD:
			return new ShieldController(type);
			break;
		case PowerupType::TRIPPLE_LASER:
			return new TrippleLaserController(type);
			break;
		default:
			return new OutscalBombController(type);
			break;
		}
	}

	void PowerupService::destroy()
	{
		for (int i = 0; i < powerup_list.size(); i++)
		{
			delete (powerup_list[i]);
		}
		powerup_list.clear();
	}

	void PowerupService::destroyFlaggedPowerups()
	{
		for (Collectible::ICollectible* powerup : flagged_powerup_list)
			delete (powerup);

		flagged_powerup_list.clear();
	}

	PowerupService::PowerupService()
	{
	}

	PowerupService::~PowerupService()
	{
		destroy();
	}

	void PowerupService::initialize()
	{
	}

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++)
		{
			powerup_list[i]->update();
		}
	}

	void PowerupService::render()
	{
		for (int i = 0; i < powerup_list.size(); i++)
		{
			powerup_list[i]->render();
		}
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType type, sf::Vector2f position)
	{
		PowerupController* controller = createPowerup(type);

		controller->initialize(position);
		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(controller));
		powerup_list.push_back(controller);
		return controller;
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(powerup_controller));

		flagged_powerup_list.push_back(powerup_controller);
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
	}
}

