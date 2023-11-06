#include "../../header/UI/MainMenu/MainMenuUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Global/Config.h"
#include "../../header/Player/HighScore.h"

namespace UI
{
    namespace MainMenu
    {
        using namespace Global;
        using namespace Main;
        using namespace Player;
        using namespace Graphics;
        using namespace Event;

        MainMenuUIController::MainMenuUIController() { game_window = nullptr; }

        void MainMenuUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeTexts();
            initializeButtons();
        }

        void MainMenuUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile(Config::background_texture_path))
            {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void MainMenuUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void MainMenuUIController::initializeTexts()
        {
            if (font.loadFromFile(Config::bubble_bobble_font_path))
            {
                high_score_text.setFont(font);
                high_score_text.setCharacterSize(font_size);
                high_score_text.setFillColor(text_color);
                high_score_text.setString("HighScore : " + std::to_string(HighScore::loadHighScore().score));
                setTextPosition(text_top_offset);
            }
        }

        void MainMenuUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool MainMenuUIController::loadButtonTexturesFromFile()
        {
            return play_button_texture.loadFromFile(Config::play_button_texture_path) &&
                instructions_button_texture.loadFromFile(Config::instructions_button_texture_path) &&
                quit_button_texture.loadFromFile(Config::quit_button_texture_path);
        }

        void MainMenuUIController::setButtonSprites()
        {
            play_button_sprite.setTexture(play_button_texture);
            instructions_button_sprite.setTexture(instructions_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }

        void MainMenuUIController::scaleAllButttons()
        {
            scaleButton(&play_button_sprite);
            scaleButton(&instructions_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void MainMenuUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

            play_button_sprite.setPosition({ x_position, play_button_top_offset });
            instructions_button_sprite.setPosition({ x_position, instructions_button_top_offset });
            quit_button_sprite.setPosition({ x_position, quit_button_top_offset });
        }

        void MainMenuUIController::update()
        {
            processButtonInteractions();
        }

        void MainMenuUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(play_button_sprite);
            game_window->draw(instructions_button_sprite);
            game_window->draw(quit_button_sprite);
            game_window->draw(high_score_text);
        }

        void MainMenuUIController::updateHighScoreText()
        {
            high_score_text.setString("HighScore : " + std::to_string(HighScore::loadHighScore().score));
        }

        void MainMenuUIController::show() { }

        void MainMenuUIController::processButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&play_button_sprite, mouse_position))
            {
                ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                GameService::setGameState(GameState::GAMEPLAY);
                ServiceLocator::getInstance()->getGameplayService()->restart();
            }

            if (clickedButton(&instructions_button_sprite, mouse_position))
            {
                ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                GameService::setGameState(GameState::INSTRUCTIONS);
            }

            if (clickedButton(&quit_button_sprite, mouse_position))
                game_window->close();
        }

        bool MainMenuUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
        }

        void MainMenuUIController::setTextPosition(float y_position)
        {
            sf::FloatRect textBounds = high_score_text.getLocalBounds();

            float x_position = (game_window->getSize().x - textBounds.width) / 2;
            high_score_text.setPosition(x_position, y_position);
        }
    }
}