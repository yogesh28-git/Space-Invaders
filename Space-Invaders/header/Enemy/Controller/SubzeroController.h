#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            const int subzero_reward = 10;
            const float subzero_rate_of_fire = 2;
            float vertical_movement_speed = 100.f;

            void move() override;
            void moveDown();

            void fireBullet() override;
            void destroy() override;

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void initialize() override;
        };
    }
}