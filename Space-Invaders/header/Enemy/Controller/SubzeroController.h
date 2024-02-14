#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            const float subzero_rate_of_fire = 5.f;
            float vertical_movement_speed = 50.f;

            void move() override;
            void moveDown();

            void fireBullet() override;

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void initialize() override;
        };
    }
}