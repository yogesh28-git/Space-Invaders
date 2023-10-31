#pragma once
#include "../../header/Enemy/EnemyController.h"

namespace Enemy
{
    namespace Controller
    {
        class ZapperController : public EnemyController
        {
        private:
            const sf::Vector2f initial_position = sf::Vector2f(50.f, 50.f);

            void moveLeft() override;
            void moveRight() override;
            void moveDown() override;
            void moveDiagonalLeft() override;
            void moveDiagonalRight() override;

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void initialize() override;
        };
    }
}