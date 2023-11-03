#pragma once
#include <SFML/Graphics.hpp>
#include "../../Collision/ICollider.h"

namespace Element
{
    namespace Bunker
    {
        class BunkerView;

        class BunkerController : public Collision::ICollider
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

            const sf::Sprite& getColliderSprite() override;
            void onCollision(ICollider* other_collider) override;
        };
    }
}