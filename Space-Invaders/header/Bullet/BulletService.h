#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../../header/Entity/EntityConfig.h"

namespace Bullet
{
	class BulletController;
	enum class BulletType;
	enum class MovementDirection;

	class BulletService
	{
	private:
		std::vector<BulletController*> bullet_list;
		std::vector<BulletController*> flagged_bullet_list;

		BulletController* createBullet(BulletType bullet_type, Entity::EntityType owner_type);

		bool isValidBullet(int index_i, std::vector<BulletController*>& bullet_list);
		void destroyFlaggedBullets();
		void destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void initialize();
		void update();
		void render();

		void reset();

		BulletController* spawnBullet(BulletType bullet_type, Entity::EntityType owner_type, sf::Vector2f position, MovementDirection direction);
		void destroyBullet(BulletController* bullet_controller);
	};
}