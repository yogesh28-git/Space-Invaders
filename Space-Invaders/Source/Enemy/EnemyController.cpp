#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h";


namespace Enemy {

	using namespace Global;

	void EnemyController::move()
	{
		switch (enemy_model->getMovementDirection()) {

		case MovementDirection::LEFT:
			moveLeft();
			break;

		case MovementDirection::RIGHT:
			moveRight();
			break;

		case MovementDirection::DOWN:
			moveDown();
			break;
		}
	}
	void EnemyController::moveLeft()
	{
		sf::Vector2f curr_position = enemy_model->getEnemyPosition();

		curr_position.x -= enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (curr_position.x <= enemy_model->left_most_position.x) {
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(curr_position);
		}
		else {
			enemy_model->setEnemyPosition(curr_position);
		}
	}
	void EnemyController::moveRight()
	{
		sf::Vector2f curr_position = enemy_model->getEnemyPosition();

		curr_position.x += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (curr_position.x >= enemy_model->right_most_position.x) {
			enemy_model->setMovementDirection(MovementDirection::DOWN);
			enemy_model->setReferencePosition(curr_position);
		}
		else {
			enemy_model->setEnemyPosition(curr_position);
		}
	}
	void EnemyController::moveDown()
	{
		sf::Vector2f curr_position = enemy_model->getEnemyPosition();

		curr_position.y += enemy_model->enemy_movement_speed * ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (curr_position.y >= enemy_model->getReferencePosition().y + enemy_model->vertical_travel_distance) {
			//Check left or right
			if (enemy_model->getReferencePosition().x <= enemy_model->left_most_position.x) {
				enemy_model->setMovementDirection(MovementDirection::RIGHT);
			}
			else {
				enemy_model->setMovementDirection(MovementDirection::LEFT);
			}
		}
		else {
			enemy_model->setEnemyPosition(curr_position);
		}
	}
	EnemyController::EnemyController()
	{
		enemy_model = new EnemyModel();
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
		enemy_view->initialize(this);
	}
	void EnemyController::update()
	{
		move();
		enemy_view->update();
	}
	void EnemyController::render()
	{
		enemy_view->render();
	}
	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}
}