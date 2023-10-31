#pragma once
#include <SFML/Graphics.hpp>

namespace Element
{
    namespace Bunker
    {
        class BunkerView;

        class BunkerController
        {
        private:
            BunkerView* bunker_view;
            sf::Vector2f bunker_position;

        public:
            BunkerController();
            ~BunkerController();

            void initialize(sf::Vector2f position);
            void update();
            void render();

            sf::Vector2f getBunkerPosition();
        };
    }
}