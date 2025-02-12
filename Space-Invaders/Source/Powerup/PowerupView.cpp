#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;

	void PowerupView::initializeImage(PowerupType type)
	{
		sf::String texture_path = " ";

		switch (type)
		{
		case PowerupType::BOMB:
			texture_path = Config::outscal_bomb_texture_path;
			break;
		case PowerupType::SHIELD:
			texture_path = Config::shield_texture_path;
			break;
		case PowerupType::RAPID_FIRE:
			texture_path = Config::rapid_fire_texture_path;
			break;
		case PowerupType::TRIPPLE_LASER:
			texture_path = Config::tripple_laser_texture_path;
			break;
		}

		if (powerup_texture.loadFromFile(texture_path))
		{
			powerup_sprite.setTexture(powerup_texture);
			scaleSprite();
		}
	}
	void PowerupView::scaleSprite()
	{
		float factorX = powerup_sprite_width / powerup_sprite.getTexture()->getSize().x;
		float factorY = powerup_sprite_height / powerup_sprite.getTexture()->getSize().y;
		powerup_sprite.setScale(factorX, factorY);
	}

	PowerupView::PowerupView()
	{
	}
	PowerupView::~PowerupView()
	{
	}
	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage(powerup_controller->getPowerupType());
	}
	void PowerupView::update()
	{
		powerup_sprite.setPosition(powerup_controller->getCollectiblePosition());
	}
	void PowerupView::render()
	{
		game_window->draw(powerup_sprite);
	}
}