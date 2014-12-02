#include "HUD.h"
#include "Component.h"
#include "DrugComponent.h"

using namespace overdose;

HUD::HUD(GameEntity* entity)
: m_Entity{ entity }, m_DrugEffect_ms{ INT_MAX }, m_CurrentEffect_ms{ INT_MAX }, m_Hearts{new std::vector<HealthHearts*> }
{
	// hearts and gauge
	m_DrugGauge = new DrugDurationGauge(posX, posY + 20);
	for (int i = 0; i < entity->getHealth(); i++)
	{
		m_Hearts->push_back(new HealthHearts(posX + i*20, posY ));
	}
	m_MaxHealth = m_Entity->getHealth();
	m_CurrentHealth = m_MaxHealth;
	posX = 20.0f;// these values should not be hardcoded :<
	posY = 440.0f;
}

HUD::~HUD()
{
	std::cout << "Deleted HUD" << std::endl; //TODO NOG TESTEN
	delete m_DrugGauge;
	m_DrugGauge = nullptr;

	for (auto h : *m_Hearts){
		delete h;
	}
	delete m_Hearts;
	m_Hearts = nullptr;
}

void HUD::tick(float dt)
{
	// loop through components list of entity
	// get the data necessary
	// set the data that it needs to draw
	// draw
	for (std::vector<Component*>::iterator it = m_Entity->getComponentList()->begin(); it != m_Entity->getComponentList()->end(); it++)
	{
		if ((*it)->getComponentID() == "DrugComponent" || (*it)->getComponentID() == "XTCDrugComponent" || (*it)->getComponentID() == "SpeedDrugComponent" || (*it)->getComponentID() == "MarijuanaDrugComponent")
		{
			std::clock_t startTime = dynamic_cast<DrugComponent*>(*it)->getStartTime();

			// u need diz trev !!!!!!!!!!!!
			int timer_end = (int)((std::clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000));
			int drug_effect_ms = dynamic_cast<DrugComponent*>(*it)->getDrugEffectMs();

			m_DrugGauge->setState(DrugDurationGauge::Gauge_Empty);
			// drug timer checker
			if (timer_end < drug_effect_ms){
				m_DrugGauge->setGaugeValue(100 - ((float)timer_end / (float)drug_effect_ms) * 100);// decrease the drug_effect bar here
				//std::cout << 100 - ((float)timer_end / (float)drug_effect_ms) * 100 << std::endl;
			}
		}
		else if ((*it)->getComponentID() == "NegativeXTCComponent" || (*it)->getComponentID() == "NegativeSpeedDrugComponent" || (*it)->getComponentID() == "NegativeXTCComponent")
		{
			std::clock_t startTime = dynamic_cast<DrugComponent*>(*it)->getStartTime();

			// u need diz trev !!!!!!!!!!!!
			int timer_end = (int)((std::clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000));
			int drug_effect_ms = dynamic_cast<DrugComponent*>(*it)->getDrugEffectMs();

			m_DrugGauge->setState(DrugDurationGauge::Gauge_Fill);
			// drug timer checker
			if (timer_end < drug_effect_ms){
				m_DrugGauge->setGaugeValue(((float)timer_end / (float)drug_effect_ms) * 100);// increase the drug_effect bar here
				//std::cout << ((float)timer_end / (float)drug_effect_ms) * 100 << std::endl;
			}
		}
		else{
			m_DrugGauge->setState(DrugDurationGauge::Gauge_Idle); // Player has no drug
		}

		m_DrugGauge->tick(dt); 

		//HealthHearts
		delayedAddHeart();
		for (std::vector<HealthHearts*>::iterator it = m_Hearts->begin(); it != m_Hearts->end(); it++)
		{
			(*it)->tick(dt);
		}

		if (m_Entity->getHealth() >= 0 && m_Hearts->size() > m_Entity->getHealth()){
			HealthHearts* heartToDelete = nullptr;
			heartToDelete = m_Hearts->back();
			heartToDelete->scheduleForRemoval();
			m_Hearts->pop_back();
			heartToDelete == nullptr;
		}
		else if (m_Entity->getHealth() > -1 && m_Hearts->size() < m_Entity->getHealth()){
			isScheduledToAddHeart = true;
		}
	}

	// do the drawing here
	// it'll have a list of other gameObjects that need to run their tick
	// that then will run their draws

}

void HUD::delayedAddHeart(){
	if (isScheduledToAddHeart){
		m_Hearts->push_back(new HealthHearts(m_Hearts->size() * 20, 0)); //new HealthHearts(posX + m_Entity->getHealth() * 20, posY)
		isScheduledToAddHeart = false;
	}
}
