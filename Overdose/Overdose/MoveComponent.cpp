#include "MoveComponent.h"
#include "GameEntity.h"

using namespace overdose;

void  MoveComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void  MoveComponent::tick(float dt, GameEntity *entity) {

	float posX = entity->getPosX();
	float posY = entity->getPosY();
	float speedX = entity->getSpeedX();
	float speedY = entity->getSpeedY();

	
	entity->setPosX(posX + speedX);
	entity->setPosY(posY + speedY);

}

