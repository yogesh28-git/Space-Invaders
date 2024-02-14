#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Enemy
{
    class EnemyController;

    class EnemyView
    {
    private:
        const sf::String enemy_texture_path = "assets/textures/enemy_ship.png";

        const float enemy_sprite_width = 60.f;
        const float enemy_sprite_height = 60.f;

        EnemyController* enemy_controller;
        UI::UIElement::ImageView* enemy_image;

        void createUIElements();
        void initializeImage();
        sf::String getEnemyTexturePath();

        void destroy();

    public:
        EnemyView();
        ~EnemyView();

        void initialize(EnemyController* controller);
        void update();
        void render();
    };
}