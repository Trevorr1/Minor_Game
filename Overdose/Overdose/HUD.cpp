#include "HUD.h"
#include "Component.h"
#include "DrugComponent.h"

using namespace overdose;

HUD::HUD(GameEntity* entity)
	: m_Entity{ entity }, m_DrugEffect_ms{ INT_MAX }, m_CurrentEffect_ms{ INT_MAX }
{
	// hearts and gauge
	m_DrugGauge = new DrugDurationGauge(posX, posY + 20);
	for (int i = 0; i < m_Hearts->size(); i++)
	{
		m_Hearts->at(i) = new HealthHearts(posX + i*20, posY );
	}
	m_MaxHealth = m_Entity->getHealth();
	m_CurrentHealth = m_MaxHealth;
	posX = 20.0f;// these values should not be hardcoded :<
	posY = 440.0f;
}

HUD::~HUD()
{
	delete m_DrugGauge;
	delete m_Hearts;
}

void HUD::tick(float dt)
{
	// loop through components list of entity
	// get the data necessary
	// set the data that it needs to draw
	// draw
	for (std::vector<Component*>::iterator it = m_Entity->getComponentList()->begin(); it != m_Entity->getComponentList()->end(); it++)
	{
		if ((*it)->getComponentID() == "DrugComponent" || "XTCDrugComponent" || "SpeedDrugComponent" || "MarijuanaDrugComponent")
		{
			std::clock_t startTime = dynamic_cast<DrugComponent*>(*it)->getStartTime();

			// u need diz trev !!!!!!!!!!!!
			int timer_end = (int)((std::clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000));
			int drug_effect_ms = dynamic_cast<DrugComponent*>(*it)->getDrugEffectMs();

			m_DrugGauge->setState(DrugDurationGauge::Gauge_Empty);
			// drug timer checker
			if (timer_end < drug_effect_ms){
				m_DrugGauge->setGaugeValue(100 - (timer_end / drug_effect_ms) * 100);
				m_DrugGauge->tick(dt);
				// decrease the drug_effect bar here
			}
		}
		else if ((*it)->getComponentID() == "NegativeXTCComponent" || "SpeedDrugComponent" || "XTCDrugComponent")
		{
			std::clock_t startTime = dynamic_cast<DrugComponent*>(*it)->getStartTime();

			// u need diz trev !!!!!!!!!!!!
			int timer_end = (int)((std::clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000));
			int drug_effect_ms = dynamic_cast<DrugComponent*>(*it)->getDrugEffectMs();

			m_DrugGauge->setState(DrugDurationGauge::Gauge_Fill);
			// drug timer checker
			if (timer_end < drug_effect_ms){
				m_DrugGauge->setGaugeValue((timer_end / drug_effect_ms) * 100);
				m_DrugGauge->tick(dt);
				// increase the drug_effect bar here
			}
		}
		for (std::vector<HealthHearts*>::iterator it = m_Hearts->begin(); it != m_Hearts->end(); it++)
		{
			(*it)->tick(dt);
		}

	}

	// do the drawing here
	// it'll have a list of other gameObjects that need to run their tick
	// that then will run their draws
}
