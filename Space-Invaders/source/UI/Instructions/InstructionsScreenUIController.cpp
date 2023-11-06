#include "../../header/UI/Instructions/InstructionsScreenUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Player/PlayerModel.h"

namespace UI
{
    namespace Instructions
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;
        using namespace Event;

        void InstructionsScreenUIController::initialize()
        {
            game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
            initializeBackgroundImage();
            initializeTexts();
            initializeButtons();
        }

        void InstructionsScreenUIController::update()
        {
            handleButtonInteractions();
        }

        void InstructionsScreenUIController::render()
        {
            game_window->draw(background_sprite);
            game_window->draw(menu_button_sprite);
            drawInstructions();
        }

        void InstructionsScreenUIController::initializeBackgroundImage()
        {
            if (background_texture.loadFromFile(Config::background_texture_path))
            {
                background_sprite.setTexture(background_texture);
                scaleBackgroundImage();
            }
        }

        void InstructionsScreenUIController::scaleBackgroundImage()
        {
            background_sprite.setScale(
                static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
                static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
            );
        }

        void InstructionsScreenUIController::initializeTexts()
        {
            if (font.loadFromFile(Config::bubble_bobble_font_path))
            {
                instructions_text.setFont(font);
                instructions_text.setCharacterSize(font_size);
                instructions_text.setFillColor(text_color);
                instructions_text.setPosition(sf::Vector2f(0.f, 0.f));
                instructions_text.setString("");
            }
        }

        void InstructionsScreenUIController::initializeButtons()
        {
            if (loadButtonTexturesFromFile())
            {
                setButtonSprites();
                scaleAllButttons();
                positionButtons();
            }
        }

        bool InstructionsScreenUIController::loadButtonTexturesFromFile()
        {
            return menu_button_texture.loadFromFile(Config::menu_button_texture_path);
        }

        void InstructionsScreenUIController::setButtonSprites()
        {
            menu_button_sprite.setTexture(menu_button_texture);
        }

        void InstructionsScreenUIController::scaleAllButttons()
        {
            scaleButton(&menu_button_sprite);
        }

        void InstructionsScreenUIController::scaleButton(sf::Sprite* button_to_scale)
        {
            button_to_scale->setScale(
                button_width / button_to_scale->getTexture()->getSize().x,
                button_height / button_to_scale->getTexture()->getSize().y
            );
        }

        void InstructionsScreenUIController::positionButtons()
        {
            float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
            menu_button_sprite.setPosition({ x_position, menu_button_top_offset });
        }

        void InstructionsScreenUIController::show() { }

        void InstructionsScreenUIController::setTextPosition(float y_position)
        {
            sf::FloatRect textBounds = instructions_text.getLocalBounds();

            float x_position = (game_window->getSize().x - textBounds.width) / 2;
            instructions_text.setPosition(x_position, y_position);
        }

        void InstructionsScreenUIController::drawInstructions()
        {
            for (int i = 0; i < number_of_instructions; i++)
            {
                instructions_text.setString(instructions[i]);
                setTextPosition(text_top_offset + (text_spacing * i));
                game_window->draw(instructions_text);
            }
        }

        void InstructionsScreenUIController::handleButtonInteractions()
        {
            sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

            if (clickedButton(&menu_button_sprite, mouse_position))
            {
                ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
                GameService::setGameState(GameState::MAIN_MENU);
            }
        }

        bool InstructionsScreenUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
        {
            EventService* event_service = ServiceLocator::getInstance()->getEventService();
            return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
        }
    }
}