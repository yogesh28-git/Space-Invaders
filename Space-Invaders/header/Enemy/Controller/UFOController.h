#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:

            void move() override;
            void moveLeft();
            void moveRight();

            void fireBullet() override;

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void initialize() override;
        };
    }
}