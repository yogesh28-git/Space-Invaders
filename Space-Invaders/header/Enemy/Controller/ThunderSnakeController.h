#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyConfig.h"

namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            void moveLeft() override;
            void moveRight() override;
            void moveDown() override;
            void moveDiagonalLeft() override;
            void moveDiagonalRight() override;

            void fireBullet() override;

            MovementDirection getInitialMovementDirection();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void initialize() override;
        };
    }
}