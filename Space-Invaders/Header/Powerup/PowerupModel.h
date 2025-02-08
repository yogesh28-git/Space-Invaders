#pragma once
#include <SFML/System/Vector2.hpp>

namespace Powerup
{
	enum class PowerupType;

	class PowerupModel
	{
	private:
		PowerupType powerup_type;
		sf::Vector2f powerup_position;
		float movement_speed = 300.0f;

	public:
		PowerupModel(PowerupType type);
		~PowerupModel();

		void initialize(sf::Vector2f position);

		float getMovementSpeed();
		void setMovementSpeed(float speed);

		sf::Vector2f getPowerupPosition();
		void setPowerupPosition(sf::Vector2f position);

		PowerupType getPowerupType();
		void setPowerupType(PowerupType type);
	};
}