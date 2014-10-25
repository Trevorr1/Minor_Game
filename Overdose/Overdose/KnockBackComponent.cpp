#include "KnockBackComponent.h"

using namespace overdose;

KnockBackComponent::KnockBackComponent()
{
}


KnockBackComponent::~KnockBackComponent()
{
}

void KnockBackComponent::receive(Component *subject, ComponentMessage message, GameEntity *object){
	if (message == HealthComponent_HEALTH_DECREASED)
	{
		hit = true;
	}
}

void KnockBackComponent::tick(float dt, GameEntity *entity)
{
	if (hit)
	{
		entity->setPosX(entity->getPosX() - knockbackValue);
		hit = false;
	}
}


std::string KnockBackComponent::getComponentID(){
	return "KnockBackComponent";
}