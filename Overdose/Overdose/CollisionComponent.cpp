#include "CollisionComponent.h"
#include "LevelManager.h"

using namespace overdose;
using namespace std;

CollisionComponent::CollisionComponent()
{
	for (int dir = 0; dir < 4; dir++)
	{
		cPoints[dir] = new cPoint{ Point{ 0, 0 }, Point{ 0, 0 } };
	}
}

CollisionComponent::~CollisionComponent()
{
	for (int dir = 0; dir < 4; dir++)
	{
		delete cPoints[dir];
	}
}

void CollisionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{
}


void CollisionComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){}

void CollisionComponent::tick(float dt, GameEntity *entity)
{
	// speedmodifier mag geen invloed hebben op springen. Krijg je rare dingen anders
	dt = (dt / LevelManager::getInstance().getSpeedModifier());

	// setup the collision points
	int posx = (int)entity->getPosX();
	int posy = (int)entity->getPosY();

	int width = (int)entity->getWidth();
	int height = (int)entity->getHeight();

	int centerX = (int)(posx + (1.0f * width / 2));
	int centerY = (int)(posy + (1.0f * height / 2));

	float nextX = entity->getSpeedX();
	float nextY = entity->getSpeedY();

	nextX *= dt;
	nextY *= dt;

	float vectorLength;
	float vectorLengthX;
	float vectorLengthY;
	int segment;
	int segmentX;
	int segmentY;
	float projectedMoveX, projectedMoveY;
	std::map<ComponentMessage, GameEntity*> messages;

	// update collision points
	updateCPoints(entity);

	vector<GameEntity*> *gameEntities = LevelManager::getInstance().getCurrentLevel()->getEntities();

	for (int i = 0; i < (int)gameEntities->size(); i++)
	{
		GameEntity* other = gameEntities->at(i);

		// assuming that only GameEntities that have collisionComponents are relevant
		// to the collision calculation
		if (entity == other || other->getEnum() == Advertisement_GameEntity || other->getEnum() == FocusPointer || other->getEnum() == Tutorial_Explanation) continue;

		// define the collision box of the "other" GameEntity
		int oposx = (int)other->getPosX();
		int oposy = (int)other->getPosY();
		int oboxw = oposx + (int)other->getWidth();
		int oboxh = oposy + (int)other->getHeight();

		ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;

		for (int dir = 0; dir < 4; dir++)
		{
			// check for collisions in the four different directions
			if ((cPoints[dir]->first.x > oposx && cPoints[dir]->first.x < oboxw) && (cPoints[dir]->first.y > oposy && cPoints[dir]->first.y  < oboxh)
				|| (cPoints[dir]->second.x  > oposx && cPoints[dir]->second.x < oboxw) && (cPoints[dir]->second.y > oposy && cPoints[dir]->second.y < oboxh))
			{
				if (other->getEnum() == Environment || other->getEnum() == Grass)
				{
					switch (dir)
					{
					case 0:
						resolveTopCollision(entity, other);
						break;
					case 1:
						resolveBotCollision(entity, other);
						break;
					case 2:
						resolveLeftCollision(entity, other);
						break;
					case 3:
						resolveRightCollision(entity, other);
						break;
					}
				}
				else
				{
					switch (dir)
					{
					case 0:
						message = CollissionComponent_REACTION_TOP;
						break;
					case 1:
						message = CollissionComponent_REACTION_BOTTOM;
						break;
					case 2:
						message = CollissionComponent_REACTION_LEFT;
						break;
					case 3:
						message = CollissionComponent_REACTION_RIGHT;
						break;
					}
				}

				if (entity->getEnum() == Player || entity->getEnum() == Policeman || entity->getEnum() == Tutorial_Policeman)
				{
					messages.insert(std::make_pair(message, other));
				}
				else
				{
					entity->broadcast(this, message, other);
					return;
				}
			}
		}
		// if the map has collisions broadcast them and end the method
		if (messages.size() > 0)
		{
			entity->broadcastBatchMessages(this, messages);
		}

		//no collisions check for btp collisions
		for (int dir = 0; dir < 4; dir++)
		{
			if (dir == 0 && (int)nextY > 0) continue;
			if (dir == 1 && (int)nextY < 0) continue;
			if (dir == 2 && (int)nextX > 0) continue;
			if (dir == 3 && (int)nextX < 0) continue;


			// Our current position along the anticipated movement vector of the player this frame
			projectedMoveX = projectedMoveY = 0;

			// Calculate the length of the movement vector using Pythagoras
			vectorLength = sqrt(nextX * nextX + nextY * nextY);
			vectorLengthX = abs(nextX);
			vectorLengthY = abs(nextY);
			segment = segmentX = segmentY = 0;

			// Advance along the vector until it intersects with some geometry
			// or we reach the end
			while (!((centerX + projectedMoveX > oposx && centerX + projectedMoveX < oboxw)
				&& (centerY + projectedMoveY > oposy && centerY + projectedMoveY < oboxh))
				&& (segment < vectorLength))
			{
				projectedMoveX += (nextX / vectorLengthX);
				segmentX++;
				projectedMoveY += (nextY / vectorLengthY);
				segmentY++;

				segment++;
			}
			if (segment < vectorLength)
			{
				if (segmentX < vectorLengthX)
				{
					if (projectedMoveX != 0.0f)
					{
						
						projectedMoveX -= (nextX / vectorLengthX);
						projectedMoveX /= dt;
						entity->setAcclX(projectedMoveX);
					}
				}

				if (segmentY < vectorLengthY)
				{
					if (projectedMoveY != 0.0f)
					{
						projectedMoveY -= (nextY / vectorLengthY);
						projectedMoveY /= dt;
						entity->setSpeedY(projectedMoveY);
					}
				}
			}
		}

	}//entitylist loop
}

std::string CollisionComponent::getComponentID(){
	return "CollisionComponent";
}

void CollisionComponent::resolveTopCollision(GameEntity *entity, GameEntity *other)
{
	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = (int)posx + (int)entity->getWidth();
	int boxY = (int)posy + (int)entity->getHeight();

	float colX = other->getPosX();
	float colY = other->getPosY();
	float colBoxX = colX + other->getWidth();
	float colBoxY = colY + other->getHeight();

	bool clear = false;

	//entity->resetGravity();
	entity->setJumpingSpeed(0);
	entity->setSpeedY(0);

	while (!clear)
	{
		entity->setPosY(posy + 1);

		posy = entity->getPosY();
		boxY = (int)posy + (int)entity->getHeight();

		if (!(posy > colY && posy < colBoxY))
			clear = true;
	}
	updateCPoints(entity);
}

void CollisionComponent::resolveBotCollision(GameEntity *entity, GameEntity *other)
{
	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = (int)posx + (int)entity->getWidth();
	int boxY = (int)posy + (int)entity->getHeight();

	float colX = other->getPosX();
	float colY = other->getPosY();

	int colBoxX = (int)colX + (int)other->getWidth();
	int colBoxY = (int)colY + (int)other->getHeight();

	bool clear = false;

	entity->setJumping(false);
	entity->setFalling(false);
	entity->resetGravity();
	entity->setSpeedY(0);

	while (!clear)
	{
		entity->setPosY(posy - 1);

		posy = entity->getPosY();
		boxY = (int)posy + (int)entity->getHeight();

		if (!(boxY > colY && boxY < colBoxY))
			clear = true;
	}
	updateCPoints(entity);
}

void CollisionComponent::resolveLeftCollision(GameEntity *entity, GameEntity *other)
{
	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = (int)posx + (int)entity->getWidth();
	int boxY = (int)posy + (int)entity->getHeight();

	bool clear = false;
	entity->resetAcclX();
	entity->setSpeedX(0);

	float colX = other->getPosX();
	float colY = other->getPosY();
	float colBoxX = colX + other->getWidth();
	float colBoxY = colY + other->getHeight();

	while (!clear)
	{
		entity->setPosX(posx + 1);

		posx = entity->getPosX();
		boxX = (int)posx + (int)entity->getWidth();

		if (!(posx > colX && posx < colBoxX))
			clear = true;
	}
	updateCPoints(entity);
}

void CollisionComponent::resolveRightCollision(GameEntity *entity, GameEntity *other)
{
	float posx = entity->getPosX();
	float posy = entity->getPosY();

	int boxX = (int)posx + (int)entity->getWidth();
	int boxY = (int)posy + (int)entity->getHeight();

	bool clear = false;

	entity->resetAcclX();
	entity->setSpeedX(0);

	float colX = other->getPosX();
	float colY = other->getPosY();
	float colBoxX = colX + other->getWidth();
	float colBoxY = colY + other->getHeight();

	while (!clear)
	{
		entity->setPosX(posx - 1);

		posx = entity->getPosX();
		boxX = (int)posx + (int)entity->getWidth();

		if (!(boxX > colX && boxX < colBoxX))
			clear = true;
	}
	updateCPoints(entity);
}

void CollisionComponent::updateCPoints(GameEntity *entity)
{
	int posx = (int)entity->getPosX();
	int posy = (int)entity->getPosY();

	int width = (int)entity->getWidth();
	int height = (int)entity->getHeight();

	int wstep = (int)(width * 1.0 / 8);
	int hstep = (int)(height * 1.0 / 3);

	// dir : 0 = top, dir : 1 = bottom, dir : 2 = left, dir : 3 = right
	// the following creates a octagon instead of a box:
	// this is to determind from which direction of the GameEntity the collsision occurs
	for (int dir = 0; dir < 4; dir++)
	{
		switch (dir){
		case 0:
			cPoints[dir]->first.x = posx + wstep;
			cPoints[dir]->first.y = posy;
			cPoints[dir]->second.x = posx + (width - wstep);
			cPoints[dir]->second.y = posy;
			break;
		case 1:
			cPoints[dir]->first.x = posx + wstep;
			cPoints[dir]->first.y = posy + height;
			cPoints[dir]->second.x = posx + (width - wstep);
			cPoints[dir]->second.y = posy + height;
			break;
		case 2:
			cPoints[dir]->first.x = posx;
			cPoints[dir]->first.y = posy + hstep;
			cPoints[dir]->second.x = posx;
			cPoints[dir]->second.y = posy + (height - hstep);
			break;
		case 3:
			cPoints[dir]->first.x = posx + width;
			cPoints[dir]->first.y = posy + hstep;
			cPoints[dir]->second.x = posx + width;
			cPoints[dir]->second.y = posy + (height - hstep);
			break;
		}
	}
}