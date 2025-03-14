#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/Config.h"

namespace Enemy {

	using namespace Global;
	using namespace Graphic;
	using namespace UI::UIElement;

	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}
	void EnemyView::initializeEnemySprite()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_width, enemy_sprite_height, enemy_controller->getEnemyPosition());
	}
	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{

		case EnemyType::ZAPPER:
			return Config::zapper_texture_path;
			break;

		case EnemyType::SUBZERO:
			return Config::subzero_texture_path;
			break;

		case EnemyType::UFO:
			return Config::ufo_texture_path;
			break;
		default: 
			return "";
			break;
		}
	}
	void EnemyView::destroy()
	{
		delete enemy_image;
	}
	EnemyView::EnemyView()
	{
		createUIElements();
	}
	EnemyView::~EnemyView()
	{
		destroy();
	}
	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		initializeEnemySprite();
	}
	void EnemyView::update()
	{
		enemy_image->update();
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
	}
	void EnemyView::render()
	{
		enemy_image->render();
	}
	sf::Vector2f EnemyView::getBarrelPositionOffset()
	{
		return barrel_position_offset;
	}
	const sf::Sprite& EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}
}