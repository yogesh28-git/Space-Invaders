#include "../Header/PlayerView.h"
#include "../Header/ServiceLocator.h"
#include "../Header/PlayerController.h"

void PlayerView::initializePlayerSprite()
{
	if (player_texture.loadFromFile(player_texture_path))
	{
		player_sprite.setTexture(player_texture);
		scalePlayerSprite();
	}
}

void PlayerView::scalePlayerSprite()
{
	float factorX = static_cast<float>(player_sprite_width) / player_texture.getSize().x;
	float factorY = static_cast<float>(player_sprite_height) / player_texture.getSize().y;

	player_sprite.setScale(factorX, factorY);
}

PlayerView::PlayerView()
{
}

PlayerView::~PlayerView()
{
}

void PlayerView::initialize(PlayerController* controller)
{
	player_controller = controller;
	game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	initializePlayerSprite();
}

void PlayerView::update()
{
	player_sprite.setPosition(player_controller->getPlayerPosition())
}

void PlayerView::render()
{
	game_window->draw(player_sprite);
}
