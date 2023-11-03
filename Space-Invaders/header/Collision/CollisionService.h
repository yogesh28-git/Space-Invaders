#pragma once
#include <vector>

namespace Collision
{
	class ICollider;

	class CollisionService
	{
	private:
		std::vector<ICollider*> collider_list;
		bool b_reset = false;

		void processCollision();
		bool isValidCollision(int index_i, int index_j);

	public:
		CollisionService();
		~CollisionService();

		void initialize();
		void update();

		void addCollider(ICollider* collider);
		void removeCollider(ICollider* collider);
	};
}