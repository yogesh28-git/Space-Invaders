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
		return BulletConfig::getBulletTexturePath(bullet_controller->getBulletType());
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