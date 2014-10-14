#include "CollisionReactionComponent.h"
#include "LevelManager.h"

using namespace overdose;
using namespace std;

CollisionReactionComponent::CollisionReactionComponent()
{
}


CollisionReactionComponent::~CollisionReactionComponent()
{
}

void CollisionReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	printf("CollisioReaction received");
	
	// resolve the collisions here
	switch (message){
	case PlayerInputComponent_ATTACK:
		printf("Attadked by player \n");
		break; 
	case CollissionComponent_COLLISION_TOP:
		printf("Collided with something from the top \n");
		break; 
	case CollissionComponent_COLLISION_BOTTOM:
		printf("Collided with something from the bottom \n");
		break; 
	case CollissionComponent_COLLISION_LEFT:
		printf("Collided with something from the left \n");
		break; 
	case CollissionComponent_COLLISION_RIGHT:
		printf("Collided with something from the right \n");
		break; 
	case Player_ATTACKING:
		printf("Player_ATTAKING?");
		isAlive = false;
		break; 
	}
}

void CollisionReactionComponent::tick(float dt, GameEntity *entity) {

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
	}
	if (collidedBottom)
	{
		entity->setSpeedY(0);
		collidedBottom = false;
	}
	if (collidedX)
	{
		entity->setSpeedX(0);
		collidedX = false;
	}
}