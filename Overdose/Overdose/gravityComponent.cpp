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

void gravityComponent::tick(float dt, GameEntity *entity)
{
	entity->setSpeedY(gravity);
}

std::string gravityComponent::getComponentID()
{
	return "gravityComponent";
}