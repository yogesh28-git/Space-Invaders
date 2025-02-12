#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Collectible/ICollectible.h"

namespace Powerup
{

	class PowerupController;
	enum class PowerupType;

	class PowerupService
	{
	private:
		std::vector<Collectible::ICollectible*> powerup_list;

		PowerupController* createPowerup(PowerupType type);
		void destroy();

	public:
		PowerupService();
		~PowerupService();

		void initialize();
		void update();
		void render();

		PowerupController* spawnPowerup(PowerupType type, sf::Vector2f position);
		void destroyPowerup(PowerupController* powerup_controller);
	};
}