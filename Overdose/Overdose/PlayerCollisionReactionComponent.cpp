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
		entity->resetAcclX();
		entity->setSpeedX(0);

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
		m_Left = nullptr;
	}
	if (collidedRight)
	{
		entity->resetAcclX();
		entity->setSpeedX(0);

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
		m_Right = nullptr;
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
		entity->setSpeedY(0);
		/*while (!clear)
		{
			entity->setPosY(posy + 1);

			posy = entity->getPosY();
			boxY = (int)posy + (int)entity->getHeight();

			if (!(posy > colY && posy < colBoxY))
				clear = true;
		}*/
		reactTop = false;
	}
	if (reactBottom)
	{
		entity->setSpeedY(0);
		entity->setJumping(false);
		entity->setFalling(false);

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
		/*while (!clear)
		{
			entity->setPosX(posx + 2);

			posx = entity->getPosX();
			boxX = (int)posx + (int)entity->getWidth();

			if (!(posx > colX && posx < colBoxX))
				clear = true;
		}*/
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