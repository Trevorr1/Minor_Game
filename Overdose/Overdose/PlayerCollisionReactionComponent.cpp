#include "PlayerCollisionReactionComponent.h"

using namespace overdose;
using namespace std;

PlayerCollisionReactionComponent::PlayerCollisionReactionComponent()
{
}


PlayerCollisionReactionComponent::~PlayerCollisionReactionComponent()
{
}


void PlayerCollisionReactionComponent::tick(float dt, GameEntity *entity)
{
	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = (int)posx + (int)entity->getWidth();
	int boxY = (int)posy + (int)entity->getHeight();

	float speedx = entity->getSpeedX();
	float speedy = entity->getSpeedY();

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
		while (!clear)
		{
			entity->setPosY(posy + 1);
			if (!(posy > colY && posy < colBoxY))
				clear = true;
		}
		collidedTop = false;
	}
	if (collidedBottom)
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy - 1);
			if (!(boxY > colY && boxY < colBoxY))
				clear = true;
		}
		collidedBottom = false;
	}
	if (collidedLeft)
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx + 2);
			if (!(posx > colX && posx < colBoxX))
				clear = true;
		}
		collidedLeft = false;
	}
	if (collidedRight)
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx - 2);
			if (!(boxX > colX && boxX < colBoxX))
				clear = true;
		}
		collidedRight = false;
	}
	if (reactTop)
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy + 1);

			posy = entity->getPosY();
			boxY = (int)posy + (int)entity->getHeight();

			if (!(posy > colY && posy < colBoxY))
				clear = true;
		}
		reactTop = false;
	}
	if (reactBottom)
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy - 1);

			posy = entity->getPosY();
			boxY = (int)posy + (int)entity->getHeight();

			if (!(boxY > colY && boxY < colBoxY))
			{
				clear = true;
			}
		}
		reactBottom = false;
	}
	if (reactLeft)
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx + 2);

			posx = entity->getPosX();
			boxX = (int)posx + (int)entity->getWidth();

			if (!(posx > colX && posx < colBoxX))
				clear = true;
		}
		reactLeft = false;
	}
	if (reactRight)
	{
		entity->setSpeedX(0);
		//while (!clear)
		//{
		//	entity->setPosX(posx - 2);

		//	posx = entity->getPosX();
		//	boxX = posx + entity->getWidth();

		//	if (!(boxX > colX && boxX < colBoxX))
		//		clear = true;
		//}
		reactRight = false;
	}

}
std::string PlayerCollisionReactionComponent::getComponentID(){
	return "PlayerCollisionReactionComponent";
}