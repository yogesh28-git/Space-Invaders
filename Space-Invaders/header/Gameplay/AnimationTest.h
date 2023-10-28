#pragma once
#include "../../header/Gameplay/Interface/ITest.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class AnimationTest : public Interface::ITest
    {
    private:
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Clock clock;

        int currentFrame;
        sf::Time frameTime;

    public:
        void initialize() override;
        void update() override;
        void render() override;
    };
}