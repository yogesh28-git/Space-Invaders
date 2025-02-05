#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Global;

	
	void BulletView::initializeImage(BulletType type)
	{
		sf::String texture_path;

		switch (type)
		{
		case BulletType::LASER:
			texture_path = Config::laser_bullet_texture_path;
			break;
		case BulletType::FROST:
			texture_path = Config::frost_beam_texture_path;
			break;
		case BulletType::TORPEDO:
			texture_path = Config::torpedoe_texture_path;
			break;
		}

		if (bullet_texture.loadFromFile(texture_path))
		{
			bullet_sprite.setTexture(bullet_texture);
			scaleSprite();
		}
	}

	void BulletView::scaleSprite()
	{
		float factorX = bullet_sprite_width / bullet_sprite.getTexture()->getSize().x;
		float factorY = bullet_sprite_height / bullet_sprite.getTexture()->getSize().y;
		bullet_sprite.setScale(factorX , factorY);
	}

	BulletView::BulletView()
	{
	}

	BulletView::~BulletView()
	{
	}

	void BulletView::initialize(BulletController* controller)
	{
		bullet_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage(bullet_controller->getBulletType());
	}

	void BulletView::update()
	{
		bullet_sprite.setPosition(bullet_controller->getProjectilePosition());
	}

	void BulletView::render()
	{
		game_window->draw(bullet_sprite);
	}

}