#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/AnimationTest.h"
#include "../../header/Gameplay/CollisionDetectionTest.h"
#include "../../header/Gameplay/SFMLTest.h"


namespace Gameplay
{
	GameplayService::GameplayService() { test = new SFMLTest(); }

	GameplayService::~GameplayService() { delete (test); }

	void GameplayService::initialize() { test->initialize(); }

	void GameplayService::update() { test->update(); }

	void GameplayService::render() { test->render(); }
}