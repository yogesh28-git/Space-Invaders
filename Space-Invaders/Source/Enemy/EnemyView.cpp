#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/Config.h"

namespace Enemy {

	using namespace Global;
	using namespace Graphic;

	void EnemyView::initializeEnemySprite(EnemyType enemy_type)
	{

		sf::String texture_path = "";

		switch (enemy_type) {

		case EnemyType::ZAPPER:
			texture_path = Config::zapper_texture_path;
			break;

		case EnemyType::SUBZERO:
			texture_path = Config::subzero_texture_path;
			break;

		case EnemyType::UFO:
			texture_path = Config::ufo_texture_path;
			break;
		}

		if (enemy_texture.loadFromFile(texture_path))
		{
			enemy_sprite.setTexture(enemy_texture);
			scaleEnemySprite();
		}
	}
	void EnemyView::scaleEnemySprite()
	{
		float factorX = enemy_sprite_width / enemy_sprite.getTexture()->getSize().x;
		float factorY = enemy_sprite_height / enemy_sprite.getTexture()->getSize().y;

		enemy_sprite.setScale(factorX, factorY);
	}
	EnemyView::EnemyView()
	{
	}
	EnemyView::~EnemyView()
	{
	}
	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeEnemySprite(enemy_controller->getEnemyType());
	}
	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
	}
	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
	sf::Vector2f EnemyView::getBarrelPositionOffset()
	{
		return barrel_position_offset;
	}
}