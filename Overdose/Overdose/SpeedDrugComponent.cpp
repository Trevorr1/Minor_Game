#include "SpeedDrugComponent.h"
//#include "GameEntity.h"


using namespace overdose;

SpeedDrugComponent::SpeedDrugComponent()
{
	//previous_speedX = getPrevious_SpeedX();
	drug_speedX = 2.0f;
	drug_effect_ms = 1000 * 5;
	//timer_start = NULL;
}


SpeedDrugComponent::~SpeedDrugComponent()
{
	printf("deleted speedDrugComponent \n");
}

void SpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void SpeedDrugComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
	//if (timer_start == NULL){
	//	timer_start = getTimer_Start();
	//}

	//if (previous_speedX == getPrevious_SpeedX()){
	//	previous_speedX = entity->getSpeedX();
	//}

	//float drugSpeed = 2.0f;
	//entity->setSpeedX(drugSpeed);

	//int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	//int drug_effect_ms = 1000 * 5;

	//// drug timer checker
	//if (timer_end < drug_effect_ms){
	//	std::cout << "Time: " << timer_end << " ms" << std::endl;
	//}
	//else{
	//	entity->setSpeedX(previous_speedX);
	//	// Delete this drug component of gameEntity
	//	entity->removeComponent(getComponentID());

	//	//Delete this SpeedDrugComponent
	//	delete this;
	//}
}

float SpeedDrugComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int SpeedDrugComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string SpeedDrugComponent::getComponentID(){
	return "SpeedDrugComponent";
}
