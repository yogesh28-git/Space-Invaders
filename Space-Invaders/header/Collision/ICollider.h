#pragma once
#include <SFML/Graphics.hpp>

namespace Collision
{
    class ICollider
    {
    public:
        virtual const sf::Sprite& getColliderSprite() = 0;
        virtual void onCollision(ICollider* other_collider) = 0;

        virtual ~ICollider() { }
    };
}