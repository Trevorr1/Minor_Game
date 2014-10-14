#include "PlayerCollisionReactionComponent.h"

using namespace overdose;
using namespace std;

PlayerCollisionReactionComponent::PlayerCollisionReactionComponent()
{
}


PlayerCollisionReactionComponent::~PlayerCollisionReactionComponent()
{
}


void PlayerCollisionReactionComponent::tick(float dt, GameEntity *entity) {

	if (!isAlive){
		//TODO how to delete?
		//vector<GameEntity*> *gameEntities = LevelManager::getInstance()->getCurrentLevel()->getEntities();
		//gameEntities->erase(gameEntities->begin() + 1);
		//delete entity;
	}
	if (collidedTop || collidedBottom)
	{
		entity->setSpeedY(0);
		collidedTop = false;
		collidedBottom = false;
	}
	if (collidedX)
	{
		entity->setSpeedX(0);
		collidedX = false;
	}
	if (reactTop || reactBottom)
	{
		entity->setSpeedY(entity->getSpeedY() * -1);
		entity->setSpeedY(entity->getSpeedX() * -1);
		reactTop = false;
		reactBottom = false;
	}
	if (reactX)
	{
		entity->setSpeedY(entity->getSpeedX() * -1);
		reactTop = false;
	}

}
std::string PlayerCollisionReactionComponent::getComponentID(){
	return "PlayerCollisionReactionComponent";
}