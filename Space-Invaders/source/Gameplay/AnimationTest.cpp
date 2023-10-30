#include "../../header/Gameplay/AnimationTest.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"

namespace Gameplay
{
	using namespace Global;
	using namespace Main;

	void AnimationTest::initialize()
	{
		if (texture.loadFromFile(texture_path)) 
		{
			sprite.setTexture(texture);
			sprite.setPosition(sprite_position);
			sprite.setScale(sprite_scale, sprite_scale);
		}

		currentFrame = 0;
		frameTime = sf::seconds(frame_duration);
	}

	void AnimationTest::update()
	{
		if (clock.getElapsedTime() >= frameTime)
		{
			currentFrame = (currentFrame + 1) % number_of_animation_frames;
			sprite.setTextureRect(sf::IntRect(currentFrame * (2 * tile_width), 0, tile_width, tile_height));
			clock.restart();
		}
	}

	void AnimationTest::render()
	{
		ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->draw(sprite);
	}
}