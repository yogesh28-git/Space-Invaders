#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class GameplayView
    {
    private:
        const float background_alpha = 150.f;

        sf::RenderWindow* game_window;
        sf::Texture background_texture;
        sf::Sprite background_sprite;

        void initializeBackgroundSprite();
        void scaleBackgroundSprite();
        void setBackgroundSpriteAlpha();

    public:
        GameplayView();
        ~GameplayView();

        void initialize();
        void update();
        void render();
    };
}