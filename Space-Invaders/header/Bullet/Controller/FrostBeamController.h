#pragma once
#include "../../header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBeamController : public BulletController
        {
        public:
            FrostBeamController(BulletType bullet_type, Entity::EntityType owner_type);
            ~FrostBeamController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}