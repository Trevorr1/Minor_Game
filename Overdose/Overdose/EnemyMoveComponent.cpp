#include "EnemyMoveComponent.h"

using namespace overdose;

EnemyMoveComponent::EnemyMoveComponent()
{

}

EnemyMoveComponent::~EnemyMoveComponent()
{

}

void  EnemyMoveComponent::receive(Component *subject, int message, GameEntity *object) 
{

}

void  EnemyMoveComponent::tick(GameEntity *entity)
{
	if (entity->getPosX() < 0 || entity->getPosX() > 500)
	{
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
}


