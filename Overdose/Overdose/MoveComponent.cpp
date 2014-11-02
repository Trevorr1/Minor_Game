#include "MoveComponent.h"
#include "GameEntity.h"
#include "LevelManager.h"

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

	if (posY > 600) { //screen height is 480 at the moment
		entity->broadcast(this, MoveComponent_OUTOFAREA, entity);
		//entity->respawn();
		LevelManager::getInstance().reloadLevel();
	}

}

std::string MoveComponent::getComponentID(){
	return "MoveComponent";
}