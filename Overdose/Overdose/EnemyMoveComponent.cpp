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
	if (entity->getPosX() < 466 - 5 || entity->getPosX() > 624 + 5)
	{
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
}

std::string EnemyMoveComponent::getComponentID(){
	return "EnemyMoveComponent";
}
