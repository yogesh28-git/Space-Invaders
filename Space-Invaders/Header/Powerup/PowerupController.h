#pragma once
#include "../../Header/Collectible/ICollectible.h"

namespace Powerup
{

	class PowerupView;
	class PowerupModel;
	enum class PowerupType;

	class PowerupController : public Collectible::ICollectible
	{
	protected:
		PowerupModel* powerup_model;
		PowerupView* powerup_view;
		
		void updatePowerupPosition();
		void handleOutOfBounds();

	public:
		PowerupController(PowerupType type);
		virtual ~PowerupController() override;

		void initialize(sf::Vector2f position);
		void update();
		void render();

		void onCollected();

		sf::Vector2f getCollectiblePosition();
		PowerupType getPowerupType();
	};
}