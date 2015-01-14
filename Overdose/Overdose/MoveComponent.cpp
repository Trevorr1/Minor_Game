#include "MoveComponent.h"
#include "GameEntity.h"
#include "LevelManager.h"

using namespace overdose;

void  MoveComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void MoveComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void  MoveComponent::tick(float dt, GameEntity *entity)
{
	float posX = entity->getPosX();
	float posY = entity->getPosY();
	float speedX = entity->getSpeedX();
	float speedY = entity->getSpeedY();
	float jspeed = entity->getJumpingSpeed();

	// speedmodifier mag geen invloed hebben op springen. Krijg je rare dingen anders
	float fakeDt = dt;
	dt = (dt / LevelManager::getInstance().getSpeedModifier());

	float addY = (speedY + jspeed) * dt;

	speedX *= fakeDt;

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
		if (entity->getEnum() == eGameEntity::Player) 
		{
			LevelManager::getInstance().getCurrentLevel()->setReloadLevel();
		}
		else 
		{
			entity->respawn();
		}
	}

}

std::string MoveComponent::getComponentID(){
	return "MoveComponent";
}