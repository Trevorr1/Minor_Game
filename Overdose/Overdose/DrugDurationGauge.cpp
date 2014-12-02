#include "DrugDurationGauge.h"
#include "DrawManager.h"

using namespace overdose;

DrugDurationGauge::DrugDurationGauge(int x, int y)
	: HUDEntity(x, y), m_GaugeValue{ (float)FULL }, m_State{Gauge_Idle}
{
	//std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();
	//animations->insert({ Default, new Animation("assets/sprites/heart.png", 2) });
	//m_DrawComponent = new DrawComponent(animations);
	//m_DrawComponent->setAnimation(Default);//set starting animation
	//addComponent(m_DrawComponent);
	m_Bar = DrawManager::getInstance().getCameraSurface(); //getSurface()
}


DrugDurationGauge::~DrugDurationGauge()
{
	std::cout << "Deleted DrugDurationGauge" << std::endl;
}

void DrugDurationGauge::tick(float dt)
{
	//int elapsed = std::min(std::max(0, m_GaugeValue - FULL), 10);

	int y = 20;
	int x = 20;

	m_Bar->Box(x, 2+y, 10+x, 66+y, 0xffffff);
	//m_Timer = timeGetTime();
	//if (m_GaugeValue >= 10) { m_Bar->Bar(4, 4, 10, 64, 0xff0000); return; }
	Pixel color = NULL;
	switch (m_State){
	case Gauge_Empty:
		color = 0x00ff00;
		break;
	case Gauge_Fill:
		color = 0xff0000;
		break;
	case Gauge_Idle:
		color = 0x808080;
		break;
	}

	//m_Bar->Bar(2+x, y+4 + 64*(m_GaugeValue / FULL), 8+x, 64 + y, color); //Increase the bar height
	m_Bar->Bar(1 + x, y-1 + 64 + 4 - 64 * (m_GaugeValue / FULL), 9 + x, 64 + y+1, color); //Decrease the bar height. HUD decides decrease or increase.
}