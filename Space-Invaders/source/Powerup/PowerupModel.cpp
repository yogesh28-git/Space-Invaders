#include "../../header/Powerup/PowerupModel.h"

namespace Powerup
{
	PowerupModel::PowerupModel(PowerupType type) 
	{
		powerup_type = type;
	}

	PowerupModel::~PowerupModel() { }

	void PowerupModel::initialize(sf::Vector2f position)
	{
		powerup_position = position;
	}

	sf::Vector2f PowerupModel::getPowerupPosition()
	{
		return powerup_position;
	}

	void PowerupModel::setPowerupPosition(sf::Vector2f position)
	{
		powerup_position = position;
	}

	PowerupType PowerupModel::getPowerupType()
	{
		return powerup_type;
	}

	void PowerupModel::setPowerupType(PowerupType type)
	{
		powerup_type = type;
	}
}
