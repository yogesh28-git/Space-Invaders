#pragma once
#include "AnimationTest.h"
#include "CollisionDetectionTest.h"
#include "SFMLTest.h"

class GameplayService
{
private:
	AnimationTest* animation_test;
	CollisionDetectionTest* collision_test;
	SFMLTest* sfml_test;

public:
	GameplayService();
	~GameplayService();

	void initialize();
	void update();
	void render();
};