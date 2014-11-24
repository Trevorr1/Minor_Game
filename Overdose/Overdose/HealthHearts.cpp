#include "HealthHearts.h"

using namespace overdose;

HealthHearts::HealthHearts()
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
