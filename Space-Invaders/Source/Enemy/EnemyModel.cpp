#include "../../Header/Enemy/EnemyModel.h"

namespace Enemy {
	EnemyModel::EnemyModel()
	{
	}
	EnemyModel::~EnemyModel()
	{
	}
	void EnemyModel::initialize()
	{
		movement_direction = MovementDirection::RIGHT;
		enemy_position = reference_position;
	}
	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}
	void EnemyModel::setReferencePosition(sf::Vector2f new_position)
	{
		reference_position = new_position;
	}
	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}
	void EnemyModel::setEnemyPosition(sf::Vector2f new_position)
	{
		enemy_position = new_position;
	}
	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}
	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}
}