#pragma once
#include "../../Header/Collectible/ICollectible.h"
#include "../../Header/Collision/ICollider.h"

namespace Powerup
{

	class PowerupView;
	class PowerupModel;
	enum class PowerupType;

	class PowerupController : public Collectible::ICollectible, public Collision::ICollider
	{
	protected:
		PowerupModel* powerup_model;
		PowerupView* powerup_view;
		
		void updatePowerupPosition();
		void handleOutOfBounds();

		virtual void applyPowerup() = 0;

	public:
		PowerupController(PowerupType type);
		virtual ~PowerupController() override;

		void initialize(sf::Vector2f position);
		void update();
		void render();

		void onCollected();

		sf::Vector2f getCollectiblePosition();
		PowerupType getPowerupType();

		const sf::Sprite& getColliderSprite();
		void onCollision(ICollider* other_collider);
	};
}