#include "gravityComponent.h"

using namespace overdose;

gravityComponent::gravityComponent()
{
	gravity = 1.0f;
}

gravityComponent::gravityComponent(float aGravity)
{
	gravity = aGravity;
}


gravityComponent::~gravityComponent()
{
}


void gravityComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{
}


void gravityComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){}

void gravityComponent::tick(float dt, GameEntity *entity)
{
	float gravityGrowth = 0.25f;
	if (entity->isJumping() || entity->isFalling())
	{
		if (gravity < m_terminalVelocity) // prevents super high gravity
			gravity += gravity * gravityGrowth;
		//if (gravity < 600.0f) // prevents jumping when walking off ledge
			//entity->setJumping(true);
	}
	else
	{
		gravity = 1.0f;
	}
	entity->setSpeedY(gravity);

}

std::string gravityComponent::getComponentID()
{
	return "gravityComponent";
}