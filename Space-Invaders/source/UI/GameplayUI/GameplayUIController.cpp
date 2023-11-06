#include "../../header/UI/GameplayUI/GameplayUIController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"
#include "../../header/Player/PlayerModel.h"

namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;

        GameplayUIController::GameplayUIController() = default;

        GameplayUIController::~GameplayUIController() = default;

        void GameplayUIController::initialize() 
        {
            initializeTexts();
            initializePlayerSprite();
        }

        void GameplayUIController::initializePlayerSprite()
        {
            if (player_texture.loadFromFile(Config::player_texture_path))
            {
                player_sprite.setTexture(player_texture);
                scalePlayerSprite();
            }
        }

        void GameplayUIController::scalePlayerSprite()
        {
            player_sprite.setScale(
                static_cast<float>(player_sprite_width) / player_sprite.getTexture()->getSize().x,
                static_cast<float>(player_sprite_height) / player_sprite.getTexture()->getSize().y
            );
        }

        void GameplayUIController::initializeTexts()
        {
            if (font.loadFromFile(Config::DS_DIGIB_font_path)) 
            {
                initializeText(score_text, "Score : 0", sf::Vector2f(score_text_x_position, text_y_position));
                initializeText(enemies_killed_text, "Enemies Killed : 0", sf::Vector2f(enemies_killed_text_x_position, text_y_position));
            }
        }

        void GameplayUIController::initializeText(sf::Text& text, sf::String initial_text, sf::Vector2f position)
        {
            text.setFont(font);
            text.setCharacterSize(font_size);
            text.setFillColor(text_color);
            text.setPosition(position);
            text.setString(initial_text);
        }

        void GameplayUIController::update()
        {
            updateScoreText();
            updateEnemiesKilledText();
        }

        void GameplayUIController::render()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            game_window->draw(score_text);
            game_window->draw(enemies_killed_text);
            drawPlayerLives();
        }

        void GameplayUIController::show() { }

        void GameplayUIController::updateScoreText()
        {
            sf::String score_string = "Score  :  " + std::to_string(PlayerModel::player_score);
            score_text.setString(score_string);
        }

        void GameplayUIController::updateEnemiesKilledText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemies_killed);
            enemies_killed_text.setString(enemies_killed_string);
        }

        void GameplayUIController::drawPlayerLives()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            for (int i = 0; i < PlayerModel::player_lives; i++)
            {
                player_sprite.setPosition(sf::Vector2f(player_lives_x_offset - (i * player_lives_spacing), player_lives_y_offset));
                game_window->draw(player_sprite);
            }
        }
    }
}