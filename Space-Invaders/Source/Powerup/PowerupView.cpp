#include "../../Header/Powerup/PowerupView.h"
#include "../../Header/Powerup/PowerupController.h"
#include "../../Header/Powerup/PowerupConfig.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;

	void PowerupView::createUIElements()
	{
		powerup_image = new ImageView();
	}

	void PowerupView::initializeImage()
	{
		powerup_image->initialize(getPowerupTexturePath(), powerup_sprite_width, powerup_sprite_height, powerup_controller->getCollectiblePosition());
	}

	sf::String PowerupView::getPowerupTexturePath()
	{
		switch (powerup_controller->getPowerupType())
		{
		case PowerupType::BOMB:
			return Config::outscal_bomb_texture_path;
			break;
		case PowerupType::SHIELD:
			return Config::shield_texture_path;
			break;
		case PowerupType::RAPID_FIRE:
			return Config::rapid_fire_texture_path;
			break;
		case PowerupType::TRIPPLE_LASER:
			return Config::tripple_laser_texture_path;
			break;
		default:
			return "";
			break;
		}
	}

	void PowerupView::destroy()
	{
		delete powerup_image;
	}

	PowerupView::PowerupView()
	{
		createUIElements();
	}
	PowerupView::~PowerupView()
	{
		destroy();
	}
	void PowerupView::initialize(PowerupController* controller)
	{
		powerup_controller = controller;
		initializeImage();
	}
	void PowerupView::update()
	{
		powerup_image->setPosition(powerup_controller->getCollectiblePosition());
		powerup_image->update();
	}
	void PowerupView::render()
	{
		powerup_image->render();
	}
}