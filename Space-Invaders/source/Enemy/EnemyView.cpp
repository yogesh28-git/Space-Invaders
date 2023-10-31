#include "../../header/Enemy/EnemyView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Main;

	EnemyView::EnemyView() { }

	EnemyView::~EnemyView() { }

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite();
	}

	void EnemyView::initializeEnemySprite()
	{
		if (enemy_texture.loadFromFile(getEnemyTexturePath()))
		{
			enemy_sprite.setTexture(enemy_texture);
			scaleEnemySprite();
		}
	}

	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}

	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}

	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyType::ZAPPER:
			return Config::zapper_texture_path;
		case::Enemy::EnemyType::THUNDER_SNAKE:
			return Config::thunder_snake_texture_path;
		case::Enemy::EnemyType::SUBZERO:
			return Config::subzero_texture_path;
		case::Enemy::EnemyType::UFO:
			return Config::ufo_texture_path;
		}
	}
}