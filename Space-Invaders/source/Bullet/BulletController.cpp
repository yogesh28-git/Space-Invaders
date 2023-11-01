#include "../../header/Bullet/BulletController.h"
#include "../../header/Bullet/BulletView.h"
#include "../../header/Bullet/BulletModel.h"
#include "../../header/Bullet/BulletConfig.h"
#include "../../header/Global/ServiceLocator.h"

namespace Bullet
{
	using namespace Global;

	BulletController::BulletController(BulletType type)
	{
		bullet_view = new BulletView();
		bullet_model = new BulletModel(type);
	}

	BulletController::~BulletController()
	{
		delete (bullet_view);
		delete (bullet_model);
	}

	void BulletController::initialize(sf::Vector2f position, MovementDirection direction)
	{
		bullet_view->initialize(this);
		bullet_model->initialize(position, direction);
	}

	void BulletController::update()
	{
		updateBulletPosition();
		bullet_view->update();
	}

	void BulletController::render()
	{
		bullet_view->render();
	}

	void BulletController::updateBulletPosition()
	{
		switch (bullet_model->getMovementDirection())
		{
		case::Bullet::MovementDirection::UP:
			moveUp();
			break;

		case::Bullet::MovementDirection::DOWN:
			moveDown();
			break;
		}
	}

	void BulletController::moveUp()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y -= movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	void BulletController::moveDown()
	{
		sf::Vector2f currentPosition = bullet_model->getBulletPosition();
		currentPosition.y += movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		bullet_model->setBulletPosition(currentPosition);
	}

	sf::Vector2f BulletController::getBulletPosition()
	{
		return bullet_model->getBulletPosition();
	}

	BulletType BulletController::getBulletType()
	{
		return bullet_model->getBulletType();
	}
}