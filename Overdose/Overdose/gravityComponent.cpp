#include "gravityComponent.h"

using namespace overdose;

gravityComponent::gravityComponent()
{
	gravity = 0.007f;
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

void gravityComponent::tick(float dt, GameEntity *entity)
{
	if (entity->isJumping() || entity->isFalling())
	{
		if (gravity < m_terminalVelocity)
			gravity += gravity * 0.08f;
		if (gravity < 0.04f)
			entity->setJumping(true);
	}
	else gravity = 0.007f;
	entity->setSpeedY(gravity);
}

std::string gravityComponent::getComponentID()
{
	return "gravityComponent";
}