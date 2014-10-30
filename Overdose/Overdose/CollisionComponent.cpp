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
}

void CollisionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void CollisionComponent::tick(float dt, GameEntity *entity) {


	// setup the collision points
	int posx = (int)entity->getPosX();
	int posy = (int)entity->getPosY();

	int width = (int)entity->getWidth();
	int height = (int)entity->getHeight();

	int wstep = (int)(width * 1.0 / 6);
	int hstep = (int)(height * 1.0 / 6);

	int nextX = (int)entity->getSpeedX();
	int nextY = (int)entity->getSpeedY();

	float vectorLength;
	int segment;
	int projectedMoveX, projectedMoveY;

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

	vector<GameEntity*> *gameEntities = LevelManager::getInstance()->getCurrentLevel()->getEntities();

	for (vector<GameEntity*>::iterator other = gameEntities->begin(); other != gameEntities->end(); ++other)
	{
	/*for (int i = 0; i < (int)gameEntities->size(); i++){
		GameEntity* other = gameEntities->at(i);*/

		// assuming that only GameEntities that have collisionComponents are relevant
		// to the collision calculation
		if (entity != *other)
		{
			// define the collision box of the "other" GameEntity
			int oposx = (int)(*other)->getPosX();
			int oposy = (int)(*other)->getPosY();
			int oboxw = oposx + (int)(*other)->getWidth();
			int oboxh = oposy + (int)(*other)->getHeight();

			// check which of the directions of this GameEntity
			// "Collides" with the other object bounding box
			bool collides = false;
			int dir;
			for (dir = 0; dir < 4 && !collides; dir++)
			{
				if (dir == 0 && nextY > 0) continue;
				if (dir == 1 && nextY < 0) continue;
				if (dir == 2 && nextX > 0) continue;
				if (dir == 3 && nextX < 0) continue;

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
					projectedMoveX += nextX / vectorLength;
					projectedMoveY += nextY / vectorLength;
					segment++;
				}


				if ((cPoints[dir]->first.x + projectedMoveX > oposx && cPoints[dir]->first.x + projectedMoveX < oboxw) && (cPoints[dir]->first.y + projectedMoveY > oposy && cPoints[dir]->first.y + projectedMoveY < oboxh)
					|| (cPoints[dir]->second.x + projectedMoveX > oposx && cPoints[dir]->second.x + projectedMoveX < oboxw) && (cPoints[dir]->second.y + projectedMoveY > oposy && cPoints[dir]->second.y + projectedMoveY < oboxh))
				{
					// If an intersection occurred...
					if (segment < vectorLength) {
						// Apply correction for over-movement
						if (segment > 0)
						{
							projectedMoveX -= nextX / vectorLength;
							projectedMoveY -= nextY / vectorLength;
						}

						// Adjust the X or Y component of the vector depending on
						// which direction we are currently testing
						if (dir >= 2 && dir <= 3)
						{
							nextX = projectedMoveX;
							entity->setSpeedX(nextX);
						}
						if (dir >= 0 && dir <= 1)
						{
							nextY = projectedMoveY;
							entity->setSpeedY(nextY);
						}
					}
					collides = true;
					break;
				}
				
			}

			/*  If there is a collision send a collision broadcast
			*	if one of the bottom point collide sent bottom collision
			*	if one of the top points collide sent top collision
			*	if the right points collide send right_collision
			*	if the left points collide send left_collision
			*	also check if it should it reacts to environment or enemies
			*/

			ComponentMessage message = CollissionComponent_COLLISION_DEFAULT;
			bool bump = ((*other)->getEnum() == Environment || (*other)->getEnum() == Grass);

			if (collides)
			{
				switch (dir){
				case 0:
					message = bump? CollissionComponent_COLLISION_TOP : CollissionComponent_REACTION_TOP;
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

				entity->broadcast(this, message, *other);
			}
		}
	}
}
std::string CollisionComponent::getComponentID(){
	return "CollisionComponent";
}