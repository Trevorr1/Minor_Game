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
	int colX = entity->getColX();
	int colY = entity->getColY();
	int colBoxX = entity->getColBoxX();
	int colBoxY = entity->getColBoxY();

	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = posx + entity->getWidth();
	int boxY = posy + entity->getHeight();

	float speedx = entity->getSpeedX();
	float speedy = entity->getSpeedY();

	bool clear = false;

	if (!entity->getAlive()){
		//TODO how to delete?
		//vector<GameEntity*> *gameEntities = LevelManager::getInstance()->getCurrentLevel()->getEntities();
		//gameEntities->erase(gameEntities->begin() + 1);
		//delete entity;
	}
	if (entity->getCollideTop())
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy + 1);

			posy = entity->getPosY();
			boxY = posy + entity->getHeight();

			if (!(posy > colY && posy < colBoxY))
				clear = true;
		}
		entity->setCollideTop(false);
		//collidedTop = false;
	}
	if (entity->getCollideBottom())
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy - 1);

			posy = entity->getPosY();
			boxY = posy + entity->getHeight();

			if (!(boxY > colY && boxY < colBoxY))
				clear = true;
		}
		entity->setCollideBottom(false);
		//collidedBottom = false;
	}
	if (entity->getCollideLeft())
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx + 2);

			posx = entity->getPosX();
			boxX = posx + entity->getWidth();

			if (!(posx > colX && posx < colBoxX))
				clear = true;
		}
		entity->setCollideLeft(false);
		//collidedLeft = false;
	}
	if (entity->getCollideRight())
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx - 2);

			posx = entity->getPosX();
			boxX = posx + entity->getWidth();

			if (!(boxX > colX && boxX < colBoxX))
				clear = true;
		}
		entity->setCollideRight(false);
		//collidedRight = false;
	}
	if (entity->getReactTop())
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy + 1);

			posy = entity->getPosY();
			boxY = posy + entity->getHeight();

			if (!(posy > colY && posy < colBoxY))
				clear = true;
		}
		entity->setReactTop(false);
		//reactTop = false;
	}
	if (entity->getReactBottom())
	{
		entity->setSpeedY(0);
		while (!clear)
		{
			entity->setPosY(posy - 1);

			posy = entity->getPosY();
			boxY = posy + entity->getHeight();

			if (!(boxY > colY && boxY < colBoxY))
			{
				clear = true;
			}
		}
		entity->setReactBottom(false);
		//reactBottom = false;
	}
	if (entity->getReactLeft())
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx + 2);

			posx = entity->getPosX();
			boxX = posx + entity->getWidth();

			if (!(posx > colX && posx < colBoxX))
				clear = true;
		}
		entity->setReactLeft(false);
		//reactLeft = false;
	}
	if (entity->getReactRight())
	{
		entity->setSpeedX(0);
		while (!clear)
		{
			entity->setPosX(posx - 2);

			posx = entity->getPosX();
			boxX = posx + entity->getWidth();

			if (!(boxX > colX && boxX < colBoxX))
				clear = true;
		}
		entity->setReactRight(false);
		//reactRight = false;
	}

}
std::string PlayerCollisionReactionComponent::getComponentID(){
	return "PlayerCollisionReactionComponent";
}