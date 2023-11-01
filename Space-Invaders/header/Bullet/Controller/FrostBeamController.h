#pragma once
#include "../../header/Bullet/BulletController.h"

namespace Bullet
{
    namespace Controller
    {
        class FrostBeamController : public BulletController
        {
        public:
            FrostBeamController(BulletType type);
            ~FrostBeamController();

            void initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}