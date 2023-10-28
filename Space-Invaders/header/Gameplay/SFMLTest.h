#pragma once
#include "../../header/Gameplay/Interface/ITest.h"
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class SFMLTest : public Interface::ITest
    {
    private:
        sf::RectangleShape rectangle_shape;

    public:
        void initialize() override;
        void update() override;
        void render() override;
    };
}