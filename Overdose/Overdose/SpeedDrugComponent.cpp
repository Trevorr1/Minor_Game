#include "SpeedDrugComponent.h"
//#include "GameEntity.h"


using namespace overdose;

SpeedDrugComponent::SpeedDrugComponent()
{
	previous_speedX = getPrevious_SpeedX();
	timer_start = getTimer_Start();
}


SpeedDrugComponent::~SpeedDrugComponent()
{
}

void SpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void SpeedDrugComponent::tick(float dt, GameEntity *entity) {
	if (previous_speedX == getPrevious_SpeedX()){
		previous_speedX = entity->getSpeedX();
	}

	float drugSpeed = 5;
	entity->setSpeedX(drugSpeed);

	int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	int drug_effect_ms = 1000 * 5;

	// drug timer checker
	if (timer_end < drug_effect_ms){
		std::cout << "Time: " << timer_end << " ms" << std::endl;
	}
	else{
		entity->setSpeedX(previous_speedX);
		// Delete this drug component of gameEntity
		entity->removeComponent(getComponentID());

		//TODO Delete this entity
		//delete entity;
		//delete this;
	}
}


std::string SpeedDrugComponent::getComponentID(){
	return "SpeedDrugComponent";
}
