#include "DrugDurationGauge.h"

using namespace overdose;

DrugDurationGauge::DrugDurationGauge(int x, int y)
	: HUDEntity(x, y), m_GaugeValue{ (float)FULL }, m_State{Gauge_Idle}
{
	std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();
	animations->insert({ Default, new Animation("assets/sprites/heart.png", 2) });
	m_DrawComponent = new DrawComponent(animations);
	m_DrawComponent->setAnimation(Default);//set starting animation
	addComponent(m_DrawComponent);
}


DrugDurationGauge::~DrugDurationGauge()
{
}

void DrugDurationGauge::tick(float dt)
{
	//int elapsed = std::min(std::max(0, m_GaugeValue - FULL), 10);
	m_Bar->Box(2, 2, 12, 66, 0xffffff);
	//m_Timer = timeGetTime();
	//if (m_GaugeValue >= 10) { m_Bar->Bar(4, 4, 10, 64, 0xff0000); return; }

	m_Bar->Bar(4, (m_GaugeValue / FULL) * 6 + 4, 10, 64, 0x00ff00);
}