#include "../../Header/UI/MainMenu/MainMenuController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Event;

		void MainMenuController::initializeBackgroundImage()
		{
			if (background_texture.loadFromFile(background_texture_path))
			{
				background_sprite.setTexture(background_texture);
				scaleBackgroundImage();
			}
		}
		void MainMenuController::scaleBackgroundImage()
		{
			float factorX = static_cast<float>(game_window->getSize().x) / (background_sprite.getTexture()->getSize().x);
			float factorY = static_cast<float>(game_window->getSize().y) / (background_sprite.getTexture()->getSize().y);
			background_sprite.setScale(factorX, factorY);
		}
		void MainMenuController::initializeButtons()
		{
			if (loadButtonTexturesFromFile())
			{
				setButtonSprites();
				scaleAllButtons();
				positionButtons();
			}
		}
		bool MainMenuController::loadButtonTexturesFromFile()
		{
			return play_button_texture.loadFromFile(play_button_texture_path) && instructions_button_texture.loadFromFile(instructions_button_texture_path) && quit_button_texture.loadFromFile(quit_button_texture_path);
		}
		void MainMenuController::setButtonSprites()
		{
			play_button_sprite.setTexture(play_button_texture);
			instructions_button_sprite.setTexture(instructions_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);
		}
		void MainMenuController::scaleAllButtons()
		{
			scaleButton(play_button_sprite);
			scaleButton(instructions_button_sprite);
			scaleButton(quit_button_sprite);
		}
		void MainMenuController::scaleButton(sf::Sprite& button_to_scale)
		{
			button_to_scale.setScale(
				button_width / button_to_scale.getTexture()->getSize().x,
				button_height / button_to_scale.getTexture()->getSize().y
			);
		}
		void MainMenuController::positionButtons()
		{
			float x_position = static_cast<float> (game_window->getSize().x / 2) - button_width / 2;

			play_button_sprite.setPosition(x_position, 500.0f);
			instructions_button_sprite.setPosition(x_position, 700.0f);
			quit_button_sprite.setPosition(x_position, 900.0f);
		}
		void MainMenuController::processButtonInteractions()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition());

			if (clickedButton(&play_button_sprite, mouse_position)) {
				GameService::setGameState(GameState::GAMEPLAY);
			}
			if (clickedButton(&instructions_button_sprite, mouse_position))
			{
				printf("Clicked instructions button");
			}
			if (clickedButton(&quit_button_sprite, mouse_position)) {
				game_window->close();
			}
		}
		bool MainMenuController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
		{
			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
		}
		MainMenuController::MainMenuController()
		{
			game_window = nullptr;
		}
		void MainMenuController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBackgroundImage();
			initializeButtons();
		}
		void MainMenuController::update()
		{
			processButtonInteractions();
		}
		void MainMenuController::render()
		{
			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(instructions_button_sprite);
			game_window->draw(quit_button_sprite);
		}
	}
}