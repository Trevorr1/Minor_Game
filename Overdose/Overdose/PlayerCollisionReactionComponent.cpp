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
	if (collidedTop)
	{
		entity->setSpeedY(0);
		collidedTop = false;
	}
	if (collidedBottom)
	{
		entity->setSpeedY(0);
		collidedBottom = false;
	}
	if (collidedX)
	{
		entity->setSpeedX(entity->getSpeedX() * -1);
		collidedX = false;
	}
}