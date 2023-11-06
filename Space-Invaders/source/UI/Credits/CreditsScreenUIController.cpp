#include "../../header/UI/Credits/CreditsScreenUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Player/PlayerModel.h"

namespace UI
{
    namespace Credits
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;
        using namespace Event;

        void CreditsScreenUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeTexts();
            initializeButtons();
        }

        void CreditsScreenUIController::update()
        {
            handleButtonInteractions();
        }

        void CreditsScreenUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(menu_button_sprite);
            game_window->draw(quit_button_sprite);
            game_window->draw(game_title_text);
        }

        void CreditsScreenUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile(Config::background_texture_path))
            {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void CreditsScreenUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void CreditsScreenUIController::initializeTexts()
        {
            if (font.loadFromFile(Config::bubble_bobble_font_path))
            {
                game_title_text.setFont(font);
                game_title_text.setCharacterSize(font_size);
                game_title_text.setFillColor(text_color);
                game_title_text.setString(game_title);
                setTextPosition(text_top_offset);
            }
        }

        void CreditsScreenUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool CreditsScreenUIController::loadButtonTexturesFromFile()
        {
            return menu_button_texture.loadFromFile(Config::menu_button_texture_path) &&
                    quit_button_texture.loadFromFile(Config::quit_button_texture_path);
        }

        void CreditsScreenUIController::setButtonSprites()
        {
            menu_button_sprite.setTexture(menu_button_texture);
            quit_button_sprite.setTexture(quit_button_texture);
        }

        void CreditsScreenUIController::scaleAllButttons()
        {
            scaleButton(&menu_button_sprite);
            scaleButton(&quit_button_sprite);
        }

        void CreditsScreenUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void CreditsScreenUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
            
            menu_button_sprite.setPosition({ x_position, menu_button_top_offset });
            quit_button_sprite.setPosition({ x_position, quit_button_top_offset });
        }

        void CreditsScreenUIController::show() { }

        void CreditsScreenUIController::setTextPosition(float y_position)
        {
            sf::FloatRect textBounds = game_title_text.getLocalBounds();

            float x_position = (game_window->getSize().x - textBounds.width) / 2;
            game_title_text.setPosition(x_position, y_position);
        }

        void CreditsScreenUIController::handleButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&menu_button_sprite, mouse_position))
            {
                ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                GameService::setGameState(GameState::MAIN_MENU);
            }
        }

        bool CreditsScreenUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
        }
    }
}