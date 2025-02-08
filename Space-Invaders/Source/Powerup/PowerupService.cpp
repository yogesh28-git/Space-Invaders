#include "../../Header/Powerup/PowerupService.h"
#include "../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	PowerupController* PowerupService::createPowerup(PowerupType type)
	{
		return nullptr;
	}

	void PowerupService::destroy()
	{
	}

	PowerupService::PowerupService()
	{
	}

	PowerupService::~PowerupService()
	{
	}

	void PowerupService::initialize()
	{
	}

	void PowerupService::update()
	{
	}

	void PowerupService::render()
	{
	}

	PowerupController* PowerupService::spawnPowerup(PowerupType type, sf::Vector2f position)
	{
		return nullptr;
	}

	void PowerupService::destroyPowerup(PowerupController*)
	{
	}

}

