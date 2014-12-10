#include "gravityComponent.h"

using namespace overdose;

gravityComponent::gravityComponent()
{
	gravity = 9.8f;
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
		//if (gravity < 100.0f) // prevents jumping when walking off ledge
		//	entity->setJumping(true);

		if (entity->getGravityState())
		{
			gravity = 9.8f;
			entity->gravityFalse();
		}

	}
	else
	{
		gravity = 9.8f;
	}
	entity->setSpeedY(gravity);

}

std::string gravityComponent::getComponentID()
{
	return "gravityComponent";
}