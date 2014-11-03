#include "EnemyMoveComponent.h"

using namespace overdose;

EnemyMoveComponent::EnemyMoveComponent()
{

}

EnemyMoveComponent::~EnemyMoveComponent()
{

}

void  EnemyMoveComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{

}

void  EnemyMoveComponent::tick(float dt, GameEntity *entity)
{

	if (entity->getPosX() < 366 - 5 || entity->getPosX() > 624 + 5)
	{
		printf("Enemy Move Component - Switching direction!\n");
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
	if (entity->getPosX() < 366 - 5) {
		entity->setPosX(370);
	}
	if (entity->getPosX() > 629) {
		entity->setPosX(628);
	}
}

std::string EnemyMoveComponent::getComponentID(){
	return "EnemyMoveComponent";
}
