#include "gravityComponent.h"

using namespace overdose;

gravityComponent::gravityComponent()
{
	gravity = 0.15f;
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
	// gravity needs to increase to create that illusion of acceleration when decending up to a cap
	// terminal velocity :/ need to do more :/
}

std::string gravityComponent::getComponentID()
{
	return "gravityComponent";
}