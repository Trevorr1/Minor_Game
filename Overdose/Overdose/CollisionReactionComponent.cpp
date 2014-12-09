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
		// check if there is a problem with multiple collisions here
		// might be cause to the fact that even though it feels more than one collision
		// it doesnt react to another entity because it only hase one entities dimensions

	}
	// resolve the collisions here
	// use object to determine with what this collided

	if (message == CollissionComponent_COLLISION_TOP)
	{
		collidedTop = true;
	}
	if (message == CollissionComponent_COLLISION_BOTTOM)
	{
		collidedBottom = true;
	}
	if (message == CollissionComponent_COLLISION_LEFT)
	{
		collidedLeft = true;
	}
	if (message == CollissionComponent_COLLISION_RIGHT)
	{
		collidedRight = true;
	}
	if (message == CollissionComponent_REACTION_TOP)
	{
		reactTop = true;
	}
	if (message == CollissionComponent_REACTION_BOTTOM)
	{
		reactBottom = true;
	}
	if (message == CollissionComponent_REACTION_LEFT)
	{
		reactLeft = true;
	}
	if (message == CollissionComponent_REACTION_RIGHT)
	{
		reactRight = true;
	}
}


void CollisionReactionComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages)
{
	for (std::map<ComponentMessage, GameEntity*>::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		switch (it->first)
		{
		case CollissionComponent_COLLISION_TOP:
			collidedTop = true;
			m_Top = it->second;
			break;
		case CollissionComponent_COLLISION_BOTTOM:
			collidedBottom = true;
			m_Bot = it->second;
			break;
		case CollissionComponent_COLLISION_LEFT:
			collidedLeft = true;
			m_Left = it->second;
			break;
		case CollissionComponent_COLLISION_RIGHT:
			collidedRight = true;
			m_Right = it->second;
			break;
		case CollissionComponent_REACTION_TOP:
			reactTop = true;
			break;
		case CollissionComponent_REACTION_BOTTOM:
			reactBottom = true;
			m_Bot = it->second;
			break;
		case CollissionComponent_REACTION_LEFT:
			reactLeft = true;
			break;
		case CollissionComponent_REACTION_RIGHT:
			reactRight = true;
			break;
		}
	}
}

std::string CollisionReactionComponent::getComponentID(){
	return "CollisionReactionComponent";
}