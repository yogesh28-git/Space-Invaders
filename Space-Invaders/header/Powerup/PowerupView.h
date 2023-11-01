#pragma once
#include <SFML/Graphics.hpp>

namespace Powerup
{
    class PowerupController;

    class PowerupView
    {
    private:
        const float powerup_sprite_width = 30.f;
        const float powerup_sprite_height = 30.f;

        PowerupController* powerup_controller;

        sf::RenderWindow* game_window;
        sf::Texture powerup_texture;
        sf::Sprite powerup_sprite;

        void initializePowerupSprite();
        void scalePowerupSprite();
        sf::String getPowerupTexturePath();

    public:
        PowerupView();
        ~PowerupView();

        void initialize(PowerupController* controller);
        void update();
        void render();
    };
}