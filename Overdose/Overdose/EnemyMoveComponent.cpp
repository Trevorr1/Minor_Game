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
	//if (entity->getPosX() < 466 - 5 || entity->getPosX() > 724 + 5)
	// Om Collision met enemy te testen, is het wel handig als deze 
	// in de buurt komt. :P
	if (entity->getPosX() < 5 || entity->getPosX() > 730)
	{
		entity->setSpeedX(entity->getSpeedX() * -1);
	}
}

std::string EnemyMoveComponent::getComponentID(){
	return "EnemyMoveComponent";
}
