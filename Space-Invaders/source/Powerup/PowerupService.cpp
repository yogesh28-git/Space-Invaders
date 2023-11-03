#include "../../header/Powerup/PowerupService.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Collision/ICollider.h"

namespace Powerup
{
	using namespace Global;
	using namespace Collision;

	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() { destroy(); }

	void PowerupService::initialize() { }

	void PowerupService::update()
	{
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->update();

		if (ServiceLocator::getInstance()->getEventService()->pressedRightMouseButton())
		{
			spawnPowerup(PowerupType::SHIELD, sf::Vector2f(100.f, 50.f));
		}
		destroyFlaggedPowerup();
	}

	void PowerupService::render()
	{
		for (int i = 0; i < powerup_list.size(); i++) powerup_list[i]->render();
	}

	PowerupController* PowerupService::createPowerup(PowerupType powerup_type)
	{
		switch (powerup_type)
		{
		case::Powerup::PowerupType::SHIELD:
			return new PowerupController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new PowerupController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new PowerupController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new PowerupController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType powerup_type, sf::Vector2f position)
	{
		PowerupController* powerup_controller = createPowerup(powerup_type);
		powerup_controller->initialize(position);

		ServiceLocator::getInstance()->getCollisionService()->addCollider(dynamic_cast<ICollider*>(powerup_controller));
		powerup_list.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::destroyFlaggedPowerup()
	{
		for (int i = 0; i < flagged_powerup_list.size(); i++) delete (flagged_powerup_list[i]);
		flagged_powerup_list.clear();
	}

	void PowerupService::destroyPowerup(PowerupController* powerup_controller)
	{
		ServiceLocator::getInstance()->getCollisionService()->removeCollider(dynamic_cast<ICollider*>(powerup_controller));

		flagged_powerup_list.push_back(powerup_controller);
		powerup_list.erase(std::remove(powerup_list.begin(), powerup_list.end(), powerup_controller), powerup_list.end());
	}

	void PowerupService::destroy()
	{
		for (int i = 0; i < powerup_list.size(); i++) delete (powerup_list[i]);
	}
}