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
	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = (int)posx + (int)entity->getWidth();
	int boxY = (int)posy + (int)entity->getHeight();
	
	bool clear = false;

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
		collidedBottom = false;
	}
	if (collidedLeft)
	{
		entity->setSpeedX(0);
		collidedLeft = false;
	}
	if (collidedRight)
	{
		entity->setSpeedX(0);
		collidedRight = false;
	}
	if (collidedBottom)
	{
		entity->setJumping(false);
		entity->setFalling(false);
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy - 1);

			posy = entity->getPosY();
			boxY = (int)posy + (int)entity->getHeight();

			if (!(boxY > colY && boxY < colBoxY))
				clear = true;
		}
		collidedBottom = false;
	}
	else
	{
		entity->setFalling(true);
	}
	if (reactTop)
	{
		reactTop = false;
	}
	if (reactBottom)
	{
		reactBottom = false;
	}
	if (reactLeft)
	{
		reactLeft = false;
	}
	if (reactRight)
	{
		reactRight = false;
	}
}

std::string PolicemanCollisionReactionComponent::getComponentID(){
	return "PolicemanCollisionReactionComponent";
}