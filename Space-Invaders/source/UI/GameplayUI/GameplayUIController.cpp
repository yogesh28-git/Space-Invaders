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

        void GameplayUIController::initialize() { initializeTexts(); }

        void GameplayUIController::initializeTexts()
        {
            if (font.loadFromFile(Config::DS_DIGIB_font_path)) 
            {
                initializeText(score_text, "Score : 0", sf::Vector2f(score_text_x_position, text_y_position));
                initializeText(enemies_killed_text, "Enemies Killed : 0", sf::Vector2f(enemies_killed_text_x_position, text_y_position));
                initializeText(bullets_fired_text, "Bullets Fired : 0", sf::Vector2f(bullets_fired_text_x_position, text_y_position));
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
            updateBulletsFiredText();
        }

        void GameplayUIController::render()
        {
            sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

            game_window->draw(score_text);
            game_window->draw(enemies_killed_text);
            game_window->draw(bullets_fired_text);
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

        void GameplayUIController::updateBulletsFiredText()
        {
            sf::String bullets_fired_string = "Bullets Fired  :  " + std::to_string(PlayerModel::bullets_fired);
            bullets_fired_text.setString(bullets_fired_string);
        }
    }
}