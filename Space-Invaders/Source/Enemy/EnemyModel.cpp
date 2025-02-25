#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy {
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemy_type = type;
	}
	EnemyModel::~EnemyModel()
	{
	}
	void EnemyModel::initialize()
	{
		enemy_state = EnemyState::PATROLLING;
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
	void EnemyModel::setMovementDirection(MovementDirection new_direction)
	{
		movement_direction = new_direction;
	}
	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}
	void EnemyModel::setEnemyType(EnemyType new_type)
	{
		enemy_type = new_type;
	}
	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}
	void EnemyModel::setEnemyState(EnemyState new_state)
	{
		enemy_state = new_state;
	}
}