#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Bullet/BulletConfig.h"

namespace Bullet
{
	using namespace Global;
	using namespace Main;

	BulletView::BulletView() { }

	BulletView::~BulletView() { }

	void BulletView::initialize(BulletController* controller)
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		bullet_controller = controller;
		initializeBulletSprite();
	}

	void BulletView::update() { bullet_sprite.setPosition(bullet_controller->getBulletPosition()); }

	void BulletView::render() { game_window->draw(bullet_sprite); }

	void BulletView::initializeBulletSprite()
	{
		if (bullet_texture.loadFromFile(getBulletTexturePath()))
		{
			bullet_sprite.setTexture(bullet_texture);
			scaleBulletSprite();
		}
	}

	void BulletView::scaleBulletSprite()
	{
		bullet_sprite.setScale(
			static_cast<float>(bullet_sprite_width) / bullet_sprite.getTexture()->getSize().x,
			static_cast<float>(bullet_sprite_height) / bullet_sprite.getTexture()->getSize().y
		);
	}

	sf::String BulletView::getBulletTexturePath()
	{
		switch (bullet_controller->getBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return Config::laser_bullet_texture_path;

		case::Bullet::BulletType::FROST_BEAM:
			return Config::frost_beam_texture_path;

		case::Bullet::BulletType::TORPEDOE:
			return Config::torpedoe_texture_path;
		}
	}
}