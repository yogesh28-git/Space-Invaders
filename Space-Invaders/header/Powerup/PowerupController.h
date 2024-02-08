#pragma once
#include "../../header/Powerup/IPowerup.h"
#include "../Collision/ICollider.h"

namespace Powerup
{
    class PowerupView;
    class PowerupModel;

    enum class PowerupType;

    class PowerupController : public IPowerup, public Collision::ICollider
    {
    protected:
        PowerupView* powerup_view;
        PowerupModel* powerup_model;

        void updatePowerupPosition();
        virtual void applyPowerup() = 0;

    public:
        PowerupController(PowerupType type);
        virtual ~PowerupController();

        void initialize(sf::Vector2f position) override;
        void update() override;
        void render() override;

        sf::Vector2f getPowerupPosition();
        PowerupType getPowerupType();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}