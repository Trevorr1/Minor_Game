#include "PolicemanCollisionReactionComponent.h"

using namespace overdose;
using namespace std;

PolicemanCollisionReactionComponent::PolicemanCollisionReactionComponent()
{
}


PolicemanCollisionReactionComponent::~PolicemanCollisionReactionComponent()
{
}

void PolicemanCollisionReactionComponent::tick(float dt, GameEntity *entity) 
{
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
		reactTop = false;
		reactBottom = false;
	}
	if (reactX)
	{
		reactTop = false;
	}
}

std::string PolicemanCollisionReactionComponent::getComponentID(){
	return "PolicemanCollisionReactionComponent";
}