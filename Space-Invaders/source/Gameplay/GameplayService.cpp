#include "../../header/Gameplay/GameplayService.h"

GameplayService::GameplayService() 
{
	collision_test = new CollisionDetectionTest();
	animation_test = new AnimationTest();
	sfml_test = new SFMLTest();
}

GameplayService::~GameplayService() 
{
	delete (collision_test);
	delete (animation_test);
	delete (sfml_test);
}

void GameplayService::initialize() 
{
	collision_test->initialize();
	animation_test->initialize();
	sfml_test->initialize();
}

void GameplayService::update() 
{
	collision_test->update();
	animation_test->update();
	sfml_test->update();
}

void GameplayService::render() 
{
	collision_test->render();
}