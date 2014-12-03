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

	if (collidedBottom)
	{
		entity->setJumping(false);
		entity->setFalling(false);
		entity->setSpeedY(0);

		colX = (int)m_Bot->getPosX();
		colY = (int)m_Bot->getPosY();
		colBoxX = colX + (int)m_Bot->getWidth();
		colBoxY = colY + (int)m_Bot->getHeight();

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
	if (collidedLeft)
	{
		entity->setSpeedX(-1 * entity->getSpeedX());

		colX = (int)m_Left->getPosX();
		colY = (int)m_Left->getPosY();
		colBoxX = colX + (int)m_Left->getWidth();
		colBoxY = colY + (int)m_Left->getHeight();

		while (!clear)
		{
			entity->setPosX(posx + 1);

			posx = entity->getPosX();
			boxX = (int)posx + (int)entity->getWidth();

			if (!(posx > colX && posx < colBoxX))
				clear = true;
		}
		collidedLeft = false;
	}
	if (collidedRight)
	{
		entity->setSpeedX(-1 * entity->getSpeedX());

		colX = (int)m_Right->getPosX();
		colY = (int)m_Right->getPosY();
		colBoxX = colX + (int)m_Right->getWidth();
		colBoxY = colY + (int)m_Right->getHeight();

		while (!clear)
		{
			entity->setPosX(posx - 1);

			posx = entity->getPosX();
			boxX = (int)posx + (int)entity->getWidth();

			if (!(boxX > colX && boxX < colBoxX))
				clear = true;
		}
		collidedRight = false;
	}
	if (collidedTop)
	{
		entity->setSpeedY(0);
		entity->setJumpingSpeed(0);

		colX = (int)m_Top->getPosX();
		colY = (int)m_Top->getPosY();
		colBoxX = colX + (int)m_Top->getWidth();
		colBoxY = colY + (int)m_Top->getHeight();

		while (!clear)
		{
			entity->setPosY(posy + 1);

			posy = entity->getPosY();
			boxY = (int)posy + (int)entity->getHeight();

			if (!(posy > colY && posy < colBoxY))
				clear = true;
		}
		collidedTop = false;
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