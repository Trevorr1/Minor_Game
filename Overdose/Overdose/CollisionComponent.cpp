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

void CollisionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}


void CollisionComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){}

void CollisionComponent::tick(float dt, GameEntity *entity) {

	// setup the collision points
	int posx = (int)entity->getPosX();
	int posy = (int)entity->getPosY();

	int width = (int)entity->getWidth();
	int height = (int)entity->getHeight();

	int wstep = (int)(width * 1.0 / 4);
	int hstep = (int)(height * 1.0 / 12);

	float nextX = entity->getSpeedX();
	float nextY = entity->getSpeedY();

	nextX *= dt;
	nextY *= dt;

	float vectorLength;
	int segment;
	float projectedMoveX, projectedMoveY;
	std::map<ComponentMessage, GameEntity*> messages;

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

	vector<GameEntity*> *gameEntities = LevelManager::getInstance().getCurrentLevel()->getEntities();

	for (int i = 0; i < (int)gameEntities->size(); i++)
	{
		GameEntity* other = gameEntities->at(i);

		// assuming that only GameEntities that have collisionComponents are relevant
		// to the collision calculation
		if (entity == other && other->getEnum() != Advertisement_GameEntity) continue;

		// define the collision box of the "other" GameEntity
		int oposx = (int)other->getPosX();
		int oposy = (int)other->getPosY();
		int oboxw = oposx + (int)other->getWidth();
		int oboxh = oposy + (int)other->getHeight();

		ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;

		for (int dir = 0; dir < 4; dir++)
		{
			// check for collisions in the four different directions
			//int dir = 0; // top
			if ((cPoints[dir]->first.x > oposx && cPoints[dir]->first.x < oboxw) && (cPoints[dir]->first.y > oposy && cPoints[dir]->first.y  < oboxh)
				|| (cPoints[dir]->second.x  > oposx && cPoints[dir]->second.x < oboxw) && (cPoints[dir]->second.y > oposy && cPoints[dir]->second.y < oboxh))
			{
				bool bump = (other->getEnum() == Environment || other->getEnum() == Grass);

				switch (dir)
				{
				case 0:
					message = bump ? CollissionComponent_COLLISION_TOP : CollissionComponent_REACTION_TOP;
					break;
				case 1:
					message = bump ? CollissionComponent_COLLISION_BOTTOM : CollissionComponent_REACTION_BOTTOM;
					break;
				case 2:
					message = bump ? CollissionComponent_COLLISION_LEFT : CollissionComponent_REACTION_LEFT;
					break;
				case 3:
					message = bump ? CollissionComponent_COLLISION_RIGHT : CollissionComponent_REACTION_RIGHT;
					break;
				}

				if (entity->getEnum() == Player || entity->getEnum() == Policeman)
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

		//if there were no collisions
		for (int dir = 0; dir < 4; dir++)
		{
			if (dir == 0 && (int)nextY >= 0) continue;
			if (dir == 1 && (int)nextY <= 0) continue;
			if (dir == 2 && (int)nextX >= 0) continue;
			if (dir == 3 && (int)nextX <= 0) continue;


			// Our current position along the anticipated movement vector of the player this frame
			projectedMoveX = projectedMoveY = 0;

			// Calculate the length of the movement vector using Pythagoras
			vectorLength = sqrt(nextX * nextX + nextY * nextY);
			segment = 0;

			// Advance along the vector until it intersects with some geometry
			// or we reach the end
			while (!((cPoints[dir]->first.x + projectedMoveX > oposx && cPoints[dir]->first.x + projectedMoveX < oboxw) && (cPoints[dir]->first.y + projectedMoveY > oposy && cPoints[dir]->first.y + projectedMoveY < oboxh)
				|| (cPoints[dir]->second.x + projectedMoveX > oposx && cPoints[dir]->second.x + projectedMoveX < oboxw) && (cPoints[dir]->second.y + projectedMoveY > oposy && cPoints[dir]->second.y + projectedMoveY < oboxh))
				&& segment < vectorLength)
			{
				projectedMoveX += (nextX / vectorLength);
				projectedMoveY += (nextY / vectorLength);
				segment++;
			}

			// If an intersection occurred...
			if (segment < vectorLength && segment > 0)
			{
				// Apply correction for over-movement
				projectedMoveX -= (nextX / vectorLength);
				projectedMoveY -= (nextY / vectorLength);

				// Adjust the X or Y component of the vector depending on
				// which direction we are currently testing
				if (dir >= 2 && dir <= 3)
				{
					projectedMoveX /= dt;
					entity->setSpeedX(projectedMoveX);
				}
				if (dir >= 0 && dir <= 1)
				{
					projectedMoveY /= dt;
					entity->setSpeedY(projectedMoveY);
				}
			}
		}
	}
}

std::string CollisionComponent::getComponentID(){
	return "CollisionComponent";
}