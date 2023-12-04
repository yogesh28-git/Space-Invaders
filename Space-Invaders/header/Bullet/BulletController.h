#pragma once
#include "../../header/Bullet/IBullet.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;

    class BulletController : public IBullet
    {
    protected:
        BulletView* bullet_view;
        BulletModel* bullet_model;

        void updateBulletPosition();

        void moveUp();
        void moveDown();

    public:
        BulletController(BulletType type);
        virtual ~BulletController();

        void initialize(sf::Vector2f position, MovementDirection direction) override;
        void update() override;
        void render() override;

        sf::Vector2f getBulletPosition();
        BulletType getBulletType();
    };
}