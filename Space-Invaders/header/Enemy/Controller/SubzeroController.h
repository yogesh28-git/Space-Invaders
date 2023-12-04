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
            const int subzero_reward = 2;

            void moveLeft() override;
            void moveRight() override;
            void moveDown() override;
            void moveDiagonalLeft() override;
            void moveDiagonalRight() override;

            void fireBullet() override;
            void destroy() override;

        public:
            SubzeroController(EnemyType type);
            ~SubzeroController();

            void initialize() override;
        };
    }
}