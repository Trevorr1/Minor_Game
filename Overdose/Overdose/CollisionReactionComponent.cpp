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
	colX = object->getPosX();
	colY = object->getPosY();
	colBoxX = colX + object->getWidth();
	colBoxY = colY + object->getHeight();
	// resolve the collisions here
	// use object to determine with what this collided
	switch (message){
	case PlayerInputComponent_ATTACK:
		printf("Attacked by player \n");
		break; 
	case CollissionComponent_COLLISION_TOP:
		printf("Collided with something from the top \n");
		collidedTop = true;
		break; 
	case CollissionComponent_COLLISION_BOTTOM:
		printf("Collided with something from the bottom \n");
		collidedBottom = true;
		break; 
	case CollissionComponent_COLLISION_LEFT:
		printf("Collided with something from the left \n");
		collidedLeft = true;
		break; 
	case CollissionComponent_COLLISION_RIGHT:
		printf("Collided with something from the right \n");
		collidedRight = true;
		break;
	case CollissionComponent_REACTION_TOP:
		printf("Reacted with something from the top \n");
		reactTop = true;
		break;
	case CollissionComponent_REACTION_BOTTOM:
		printf("Reacted with something from the bottom \n");
		reactBottom = true;
		break; 
	case CollissionComponent_REACTION_LEFT:
		printf("Reacted with something from the left \n");
		reactLeft = true;
		break;
	case CollissionComponent_REACTION_RIGHT:
		printf("Reacted with something from the right \n");
		reactRight = true;
		break;
	case Player_ATTACKING:
		printf("Player_ATTACKING? \n");
		isAlive = false;
		break; 
	defualt:
		// do nothing for now
		break;
	}
}

std::string CollisionReactionComponent::getComponentID(){
	return "CollisionReactionComponent";
}