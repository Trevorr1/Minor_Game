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
		printf("Attacked by player");
		break; 
	case CollissionComponent_COLLISION_TOP:
		printf("Collided with something from the top");
		collidedTop = true;
		break; 
	case CollissionComponent_COLLISION_BOTTOM:
		printf("Collided with something from the bottom");
		collidedBottom = true;
		break; 
	case CollissionComponent_COLLISION_LEFT:
		printf("Collided with something from the left");
		collidedX = true;
		break; 
	case CollissionComponent_COLLISION_RIGHT:
		printf("Collided with something from the right");
		collidedX = true;
		break; 
	case Player_ATTACKING:
		printf("Player_ATTAKING?");
		isAlive = false;
		break; 
	defualt:

		break;
	}
}
