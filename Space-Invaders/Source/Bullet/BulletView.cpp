#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;

	void BulletView::createUIElements()
	{
		bullet_image = new ImageView();
	}

	void BulletView::initializeImage()
	{
		bullet_image->initialize(getBulletTexturePath(), bullet_sprite_width, bullet_sprite_height, bullet_controller->getProjectilePosition());
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case BulletType::LASER:
			return Config::laser_bullet_texture_path;
			break;
		case BulletType::FROST:
			return Config::frost_beam_texture_path;
			break;
		case BulletType::TORPEDO:
			return Config::torpedoe_texture_path;
			break;
		default: 
			return "";
			break;
		}
	}

	void BulletView::destroy()
	{
		delete bullet_image;
	}

	BulletView::BulletView()
	{
		createUIElements();
	}

	BulletView::~BulletView()
	{
		destroy();
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		initializeImage();
	}

	void BulletView::update()
	{
		bullet_image->update();
		bullet_image->setPosition(bullet_controller->getProjectilePosition());
	}

	void BulletView::render()
	{
		bullet_image->render();
	}

	const sf::Sprite& BulletView::getBulletSprite()
	{
		return bullet_image->getSprite();
	}

}