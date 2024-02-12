#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class SubzeroController : public EnemyController
        {
        private:
            const float subzero_rate_of_fire = 3.f;
            const int subzero_reward = 2;
            const float subzero_vertical_movement_speed = 70.f;

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