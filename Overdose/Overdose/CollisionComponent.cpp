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

	int wstep = (int)(width * 1.0 / 3);
	int hstep = (int)(height * 1.0 / 10);

	int nextX = (int)entity->getSpeedX();
	int nextY = (int)entity->getSpeedY();

	float vectorLength;
	int segment;
	int projectedMoveX, projectedMoveY;
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

	for (int i = 0; i < (int)gameEntities->size(); i++){
		GameEntity* other = gameEntities->at(i);

		// assuming that only GameEntities that have collisionComponents are relevant
		// to the collision calculation
		if (entity != other)
		{

			// define the collision box of the "other" GameEntity
			int oposx = (int)other->getPosX();
			int oposy = (int)other->getPosY();
			int oboxw = oposx + (int)other->getWidth();
			int oboxh = oposy + (int)other->getHeight();

			// check for collisions in the four different directions
			int dir = 0; // top
			if ((cPoints[dir]->first.x > oposx && cPoints[dir]->first.x < oboxw) && (cPoints[dir]->first.y > oposy && cPoints[dir]->first.y  < oboxh)
				|| (cPoints[dir]->second.x  > oposx && cPoints[dir]->second.x < oboxw) && (cPoints[dir]->second.y > oposy && cPoints[dir]->second.y < oboxh))
			{
				ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;
				bool bump = (other->getEnum() == Environment || other->getEnum() == Grass);
				message = bump ? CollissionComponent_COLLISION_TOP : CollissionComponent_REACTION_TOP;
				
				messages.insert( std::make_pair(message, other));
			}

			dir = 1; // bottom
			if ((cPoints[dir]->first.x > oposx && cPoints[dir]->first.x < oboxw) && (cPoints[dir]->first.y > oposy && cPoints[dir]->first.y  < oboxh)
				|| (cPoints[dir]->second.x  > oposx && cPoints[dir]->second.x < oboxw) && (cPoints[dir]->second.y > oposy && cPoints[dir]->second.y < oboxh))
			{
				ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;
				bool bump = (other->getEnum() == Environment || other->getEnum() == Grass);
				message = bump ? CollissionComponent_COLLISION_BOTTOM : CollissionComponent_REACTION_BOTTOM;
				
				messages.insert(std::make_pair(message, other));
			}

			dir = 2; // left
			if ((cPoints[dir]->first.x > oposx && cPoints[dir]->first.x < oboxw) && (cPoints[dir]->first.y > oposy && cPoints[dir]->first.y  < oboxh)
				|| (cPoints[dir]->second.x  > oposx && cPoints[dir]->second.x < oboxw) && (cPoints[dir]->second.y > oposy && cPoints[dir]->second.y < oboxh))
			{
				ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;
				bool bump = (other->getEnum() == Environment || other->getEnum() == Grass);
				message = bump ? CollissionComponent_COLLISION_LEFT : CollissionComponent_REACTION_LEFT;
				
				messages.insert(std::make_pair(message, other));
			}

			dir = 3; // right
			if ((cPoints[dir]->first.x > oposx && cPoints[dir]->first.x < oboxw) && (cPoints[dir]->first.y > oposy && cPoints[dir]->first.y  < oboxh)
				|| (cPoints[dir]->second.x  > oposx && cPoints[dir]->second.x < oboxw) && (cPoints[dir]->second.y > oposy && cPoints[dir]->second.y < oboxh))
			{

				ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;
				bool bump = (other->getEnum() == Environment || other->getEnum() == Grass);
				message = bump ? CollissionComponent_COLLISION_RIGHT : CollissionComponent_REACTION_RIGHT;
				
				messages.insert(std::make_pair(message, other));
			}

			for (int d = 0; d < 4; d++)
			{

				if (d == 0 && nextY > 0) continue;
				if (d == 1 && nextY < 0) continue;
				if (d == 2 && nextX > 0) continue;
				if (d == 3 && nextX < 0) continue;


				// Our current position along the anticipated movement vector of the player this frame
				projectedMoveX = projectedMoveY = 0;

				// Calculate the length of the movement vector using Pythagoras
				vectorLength = (float)sqrt(nextX * nextX + nextY * nextY);
				segment = 0;

				// Advance along the vector until it intersects with some geometry
				// or we reach the end
				while (!((cPoints[d]->first.x + projectedMoveX > oposx && cPoints[d]->first.x + projectedMoveX < oboxw) && (cPoints[d]->first.y + projectedMoveY > oposy && cPoints[d]->first.y + projectedMoveY < oboxh)
					|| (cPoints[d]->second.x + projectedMoveX > oposx && cPoints[d]->second.x + projectedMoveX < oboxw) && (cPoints[d]->second.y + projectedMoveY > oposy && cPoints[d]->second.y + projectedMoveY < oboxh))
					&& segment < vectorLength)
				{
					projectedMoveX += (int)(nextX / vectorLength);
					projectedMoveY += (int)(nextY / vectorLength);
					segment++;
				}

				// If an intersection occurred...
				if (segment < vectorLength)
				{
					// Apply correction for over-movement
					if (segment > 0)
					{
						projectedMoveX -= (int)(nextX / vectorLength);
						projectedMoveY -= (int)(nextY / vectorLength);
					}

					// Adjust the X or Y component of the vector depending on
					// which direction we are currently testing
					if (d >= 2 && d <= 3)
					{
						nextX = projectedMoveX;
						entity->setSpeedX((float)nextX);
					}
					if (d >= 0 && d <= 1)
					{
						nextY = projectedMoveY;
						entity->setSpeedY((float)nextY);
					}
				}
			}

			entity->broadcastBatchMessages(this, messages);
		}
	}
}
std::string CollisionComponent::getComponentID(){
	return "CollisionComponent";
}