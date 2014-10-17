#include "SpeedDrugComponent.h"
//#include "GameEntity.h"


using namespace overdose;

SpeedDrugComponent::SpeedDrugComponent()
{
	/*previous_speedX = -999;
	timer_start = std::clock();*/
	DrugComponent();// waarom werkt Speedx niet -999?

}


SpeedDrugComponent::~SpeedDrugComponent()
{
}

void SpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void SpeedDrugComponent::tick(float dt, GameEntity *entity) {
	if (previous_speedX == -999){
		previous_speedX = entity->getSpeedX();
	}

	float drugSpeed = 30;
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
	}
}

std::string SpeedDrugComponent::getComponentID(){
	return "SpeedDrugComponent";
}
