#include "HealthHearts.h"

using namespace overdose;

HealthHearts::HealthHearts(int x, int y) 
	: HUDEntity(x, y), m_State{Heart_Full}
{
	std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();
	animations->insert({ Default, new Animation("assets/sprites/heart.png", 2) });
	m_DrawComponent = new DrawComponent(animations);
	m_DrawComponent->setAnimation(Default);//set starting animation
	addComponent(m_DrawComponent);
}


HealthHearts::~HealthHearts()
{
}

void HealthHearts::tick(float dt)
{
	m_DrawComponent->tick(dt, this);
}
