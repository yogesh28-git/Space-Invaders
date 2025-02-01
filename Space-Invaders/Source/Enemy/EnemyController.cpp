#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h";


namespace Enemy {

	using namespace Global;

	void EnemyController::move()
	{
		
	}
	sf::Vector2f EnemyController::getRandomInitialPosition()
	{
		int x_offset = std::rand() % (static_cast<int>(enemy_model->right_most_position.x - enemy_model->left_most_position.x));

		float x_position = enemy_model->left_most_position.x + x_offset;
		float y_position = enemy_model->left_most_position.y;

		return sf::Vector2f(x_position, y_position);
	}
	void EnemyController::handleOutOfBounds()
	{
		sf::Vector2f position = enemy_model->getEnemyPosition();
		sf::Vector2u window_size = ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize();

		if (position.x < 0 || position.x > window_size.x || position.y < 0 || position.y > window_size.y)
		{
			ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
		}
	}
	/*
	void enemycontroller::moveleft()
	{
		sf::vector2f curr_position = enemy_model->getenemyposition();

		curr_position.x -= enemy_model->enemy_movement_speed * servicelocator::getinstance()->gettimeservice()->getdeltatime();

		if (curr_position.x <= enemy_model->left_most_position.x) {
			enemy_model->setmovementdirection(movementdirection::down);
			enemy_model->setreferenceposition(curr_position);
		}
		else {
			enemy_model->setenemyposition(curr_position);
		}
	}
	void enemycontroller::moveright()
	{
		sf::vector2f curr_position = enemy_model->getenemyposition();

		curr_position.x += enemy_model->enemy_movement_speed * servicelocator::getinstance()->gettimeservice()->getdeltatime();

		if (curr_position.x >= enemy_model->right_most_position.x) {
			enemy_model->setmovementdirection(movementdirection::down);
			enemy_model->setreferenceposition(curr_position);
		}
		else {
			enemy_model->setenemyposition(curr_position);
		}
	}
	void enemycontroller::movedown()
	{
		sf::vector2f curr_position = enemy_model->getenemyposition();

		curr_position.y += enemy_model->enemy_movement_speed * servicelocator::getinstance()->gettimeservice()->getdeltatime();

		if (curr_position.y >= enemy_model->getreferenceposition().y + enemy_model->vertical_travel_distance) {
			//check left or right
			if (enemy_model->getreferenceposition().x <= enemy_model->left_most_position.x) {
				enemy_model->setmovementdirection(movementdirection::right);
			}
			else {
				enemy_model->setmovementdirection(movementdirection::left);
			}
		}
		else {
			enemy_model->setenemyposition(curr_position);
		}
	}
	*/

	EnemyController::EnemyController(EnemyType type)
	{
		enemy_model = new EnemyModel(type);
		enemy_view = new EnemyView();
	}
	EnemyController::~EnemyController()
	{
		delete enemy_model;
		enemy_model = nullptr;

		delete enemy_view;
		enemy_view = nullptr;
	}
	void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_model->setEnemyPosition(getRandomInitialPosition());
		enemy_view->initialize(this);
	}
	void EnemyController::update()
	{
		move();
		enemy_view->update();
		handleOutOfBounds();
	}
	void EnemyController::render()
	{
		enemy_view->render();
	}
	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
	EnemyType EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}
	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}
}