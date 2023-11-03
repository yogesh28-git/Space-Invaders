#include "../../header/Powerup/PowerupView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Global/Config.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Powerup/PowerupController.h"
#include "../../header/Powerup/PowerupConfig.h"

namespace Powerup
{
	using namespace Global;
	using namespace Main;

	PowerupView::PowerupView() { }

	PowerupView::~PowerupView() { }

	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePowerupSprite();
	}

	void PowerupView::initializePowerupSprite()
	{
		if (powerup_texture.loadFromFile(getPowerupTexturePath()))
		{
			powerup_sprite.setTexture(powerup_texture);
			scalePowerupSprite();
		}
	}

	void PowerupView::scalePowerupSprite()
	{
		powerup_sprite.setScale(
			static_cast<float>(powerup_sprite_width) / powerup_sprite.getTexture()->getSize().x,
			static_cast<float>(powerup_sprite_height) / powerup_sprite.getTexture()->getSize().y
		);
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->getPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shield_texture_path;

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscal_bomb_texture_path;
		}
	}

	void PowerupView::update() { powerup_sprite.setPosition(powerup_controller->getPowerupPosition()); }

	void PowerupView::render() { game_window->draw(powerup_sprite); }

	const sf::Sprite& PowerupView::getPowerupSprite() { return powerup_sprite; }
}