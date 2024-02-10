#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Gameplay
{
    class GameplayController;

    class GameplayView
    {
    private:
        const float background_alpha = 150.f;

        GameplayController* gameplay_controller;
        UI::UIElement::ImageView* background_image;

        void initializeBackgroundImage();

    public:
        GameplayView();
        ~GameplayView();

        void initialize();
        void update();
        void render();
    };
}