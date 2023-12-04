#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:
            const int ufo_reward = 0;

            void moveLeft() override;
            void moveRight() override;
            void moveDown() override;
            void moveDiagonalLeft() override;
            void moveDiagonalRight() override;

            void fireBullet() override;
            void destroy() override;
            Powerup::PowerupType getRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void initialize() override;
            void onCollision(ICollider* other_collider) override;
        };
    }
}