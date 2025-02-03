#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace Gameplay {

	using namespace Global;

	void GameplayView::initializeBackground()
	{
		if(background_texture.loadFromFile(Config::background_texture_path)) 
		{
			background_sprite.setTexture(background_texture);
			scaleBackground();
		}
	}
	void GameplayView::scaleBackground()
	{
		background_sprite.setScale(
			static_cast<float> (game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
			static_cast<float> (game_window->getSize().y) / background_sprite.getTexture()->getSize().y
		);
	}
	GameplayView::GameplayView()
	{
	}
	GameplayView::~GameplayView()
	{
	}
	void GameplayView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeBackground();
	}
	void GameplayView::update()
	{
	}
	void GameplayView::render()
	{
		game_window->draw(background_sprite);
	}
}