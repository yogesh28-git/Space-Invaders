#pragma once
#include "../../header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBeamController : public BulletController
        {
        private:
            const float frost_beam_movement_speed = 250.f;

        public:
            FrostBeamController(BulletType bullet_type, Entity::EntityType owner_type);
            ~FrostBeamController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}