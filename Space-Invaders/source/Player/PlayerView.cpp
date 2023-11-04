#include "../../header/Player/PlayerView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	using namespace Global;
	using namespace Main;

	PlayerView::PlayerView() { }

	PlayerView::~PlayerView() { }

	void PlayerView::initialize(PlayerController* controller)
	{
		player_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializePlayerSprite();
	}

	void PlayerView::initializePlayerSprite()
	{
		if (player_texture.loadFromFile(Config::player_texture_path))
		{
			player_sprite.setTexture(player_texture);
			scalePlayerSprite();
		}
	}

	void PlayerView::scalePlayerSprite()
	{
		player_sprite.setScale(
			static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
			static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y
		);
	}

	void PlayerView::update()
	{
		player_sprite.setPosition(player_controller->getPlayerPosition());
	}

	void PlayerView::render()
	{
		game_window->draw(player_sprite);
	}

	void PlayerView::setPlayerHighlight(bool b_highlight)
	{
		sf::Color player_color = player_sprite.getColor();

		if (b_highlight) player_color.a = invincible_player_alpha;
		else player_color.a = 255;
		
		player_sprite.setColor(player_color);
	}

	const sf::Sprite& PlayerView::getPlayerSprite()
	{
		return player_sprite;
	}
}