#include "../../header/Gameplay/AnimationTest.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;

	void AnimationTest::initialize()
	{
		if (texture.loadFromFile("assets/textures/pacman_death.png")) 
		{
			sprite.setTexture(texture);
			sprite.setPosition(940, 490);
			sprite.setScale(5,5);
		}

		currentFrame = 0;
		frameTime = sf::seconds(0.2f);
	}

	void AnimationTest::update()
	{
		if (clock.getElapsedTime() >= frameTime)
		{
			currentFrame = (currentFrame + 1) % 12; // Assuming 6 frames in the animation
			sprite.setTextureRect(sf::IntRect(currentFrame * 32, 0, 16, 16)); // Adjust based on your sprite size
			clock.restart();
		}
	}

	void AnimationTest::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(sprite);
	}
}