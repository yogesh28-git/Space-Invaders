#pragma once
#include "../../header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class LaserBulletController : public BulletController
        {
        public:
            LaserBulletController(BulletType bullet_type, Entity::EntityType owner_type);
            ~LaserBulletController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}
