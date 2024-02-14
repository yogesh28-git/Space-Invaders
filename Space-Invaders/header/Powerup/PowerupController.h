#pragma once
#include "../../header/Powerup/IPowerup.h"

namespace Powerup
{
    class PowerupView;
    class PowerupModel;

    enum class PowerupType;

    class PowerupController : public IPowerup
    {
    protected:
        PowerupView* powerup_view;
        PowerupModel* powerup_model;

        void updatePowerupPosition();

    public:
        PowerupController(PowerupType type);
        virtual ~PowerupController();

        void initialize(sf::Vector2f position) override;
        void update() override;
        void render() override;

        sf::Vector2f getPowerupPosition();
        PowerupType getPowerupType();
    };
}