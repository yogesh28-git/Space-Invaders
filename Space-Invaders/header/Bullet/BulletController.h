#pragma once
#include "../../header/Bullet/IBullet.h"
#include "../../header/Entity/EntityConfig.h"
#include "../Collision/ICollider.h"

namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;

    class BulletController : public IBullet, public Collision::ICollider
    {
    protected:
        float movement_speed = 500.f;

        BulletView* bullet_view;
        BulletModel* bullet_model;

        void updateBulletPosition();

        void moveUp();
        void moveDown();

    public:
        BulletController(BulletType bullet_type, Entity::EntityType owner_type);
        virtual ~BulletController();

        void initialize(sf::Vector2f position, MovementDirection direction) override;
        void update() override;
        void render() override;

        sf::Vector2f getBulletPosition();
        BulletType getBulletType();
        Entity::EntityType getOwnerEntityType();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}