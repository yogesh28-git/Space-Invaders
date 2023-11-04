#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Global/ServiceLocator.h"
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

	const sf::Sprite& BulletView::getBulletSprite() { return bullet_sprite; }

	void BulletView::initializeBulletSprite()
	{
		if (bullet_texture.loadFromFile(BulletConfig::getBulletTexturePath(bullet_controller->getBulletType())))
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
}