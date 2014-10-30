#include "MoveComponent.h"
#include "GameEntity.h"

using namespace overdose;

void  MoveComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void  MoveComponent::tick(float dt, GameEntity *entity) {

	float posX = entity->getPosX();
	float posY = entity->getPosY();
	float speedX = entity->getSpeedX() * dt;
	float speedY = entity->getSpeedY();
	float jspeed = entity->getJumpingSpeed();

	float addY = (speedY + jspeed) * dt;

	entity->setPosX(posX + speedX);
	entity->setPosY(posY + addY);

	if (jspeed >= 0)
	{
		entity->setJumpingSpeed(0);
	}
	else
	{
		jspeed += speedY;
		entity->setJumpingSpeed(jspeed);
	}

	if (posY > 1000) {
		entity->broadcast(this, MoveComponent_OUTOFAREA, entity);
		entity->setPosY(0);
	}

}

std::string MoveComponent::getComponentID(){
	return "MoveComponent";
}