#pragma once
#include <vector>

namespace Collision
{
	class ICollider;

	class CollisionService
	{
	private:
		std::vector<ICollider*> collider_list;

		void processCollision();

	public:
		CollisionService();
		~CollisionService();

		void initialize();
		void update();
		void render();

		void addCollider(ICollider* collider);
		void removeCollider(ICollider* collider);
	};
}