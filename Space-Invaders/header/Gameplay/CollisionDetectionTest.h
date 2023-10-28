#pragma once
#include "../../header/Gameplay/Interface/ITest.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class CollisionDetectionTest : public Interface::ITest
    {
    private:
        sf::RectangleShape rectangle_shape_one;
        sf::RectangleShape rectangle_shape_two;

        void updateRectanglePosition();

    public:
        void initialize() override;
        void update() override;
        void render() override;
    };
}