#include "HUD.h"
#include "Component.h"
#include "DrugComponent.h"

using namespace overdose;

HUD::HUD()
	: m_Entity{ nullptr }, m_MaxHealth{ 0 }, m_CurrentHealth{ 0 }, m_DrugEffect_ms{ INT_MAX }, m_CurrentEffect_ms{ INT_MAX }
{
	// hearts and gauge
	posX = 20.0f;
	posY = 440.0f;
}

HUD::HUD(GameEntity* entity)
	: m_Entity{ entity }, m_DrugEffect_ms{ INT_MAX }, m_CurrentEffect_ms{ INT_MAX }
{
	// hearts and gauge
	m_DrugGauge = new DrugDurationGauge();
	for (std::vector<HealthHearts*>::iterator it = m_Hearts->begin(); it != m_Hearts->end(); it++)
	{
		*it = new HealthHearts();
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

			// drug timer checker
			if (timer_end < drug_effect_ms){
				// decrease the drug_effect bar here
			}
		}
		else if ((*it)->getComponentID() == "NegativeXTCComponent" || "SpeedDrugComponent" || "XTCDrugComponent")
		{
			std::clock_t startTime = dynamic_cast<DrugComponent*>(*it)->getStartTime();

			// u need diz trev !!!!!!!!!!!!
			int timer_end = (int)((std::clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000));
			int drug_effect_ms = dynamic_cast<DrugComponent*>(*it)->getDrugEffectMs();

			// drug timer checker
			if (timer_end < drug_effect_ms){
				// increase the drug_effect bar here
			}
		}
	}

	// do the drawing here
	// it'll have a list of other gameObjects that need to run their tick
	// that then will run their draws
}
