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
	if (object != nullptr)
	{
	//	printf("CollisioReaction received");
		colX = (int)object->getPosX();
		colY = (int)object->getPosY();
		colBoxX = colX + (int)object->getWidth();
		colBoxY = colY + (int)object->getHeight();
	}
	// resolve the collisions here
	// use object to determine with what this collided
	switch (message){
	case PlayerInputComponent_ATTACK:
		break; 
	case CollissionComponent_COLLISION_TOP:
		collidedTop = true;
		break; 
	case CollissionComponent_COLLISION_BOTTOM:
		collidedBottom = true;
		break; 
	case CollissionComponent_COLLISION_LEFT:
		collidedLeft = true;
		break; 
	case CollissionComponent_COLLISION_RIGHT:
		collidedRight = true;
		break;
	case CollissionComponent_REACTION_TOP:
		reactTop = true;
		break;
	case CollissionComponent_REACTION_BOTTOM:
		reactBottom = true;
		break; 
	case CollissionComponent_REACTION_LEFT:
		reactLeft = true;
		break;
	case CollissionComponent_REACTION_RIGHT:
		reactRight = true;
		break;
	case Player_ATTACKING:
		isAlive = false;
		break; 
	default:
		// do nothing for now
		break;
	}
}

std::string CollisionReactionComponent::getComponentID(){
	return "CollisionReactionComponent";
}