#include "DrugComponent.h"
#include "GameEntity.h"



using namespace overdose;

DrugComponent::DrugComponent()
{
	previous_speedX = -999;
	timer_start = NULL;
}


DrugComponent::~DrugComponent()
{
	printf("deleted DrugComponent \n");
}

void DrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void DrugComponent::tick(float dt, GameEntity *entity) {
	if (timer_start == NULL){
		timer_start = getTimer_Start();
	}

	if (previous_speedX == -999){
		previous_speedX = entity->getSpeedX();
	}

	entity->setSpeedX(getDrugSpeed_X());

	int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	int drug_effect_ms = getDrugEffectMs();

	// drug timer checker
	if (timer_end < drug_effect_ms){
		//std::cout << "Time: " << timer_end << " ms" << std::endl;
	}
	else{
		entity->setSpeedX(previous_speedX);
		// Delete this drug component of gameEntity
		entity->removeComponent(getComponentID());
		insertNegativeEffect(entity);
		//delete this drugcomponent
		// entity->insertNegativeEffect
		//delete this;
	}
}



float DrugComponent::getPrevious_SpeedX(){
	return previous_speedX;
}

int DrugComponent::getTimer_Start(){
	return std::clock();
}

float DrugComponent::getDrugSpeed_X(){
	return NULL;
}

int DrugComponent::getDrugEffectMs(){
	return NULL;
}

std::string DrugComponent::getComponentID(){
	return "DrugComponent";
}

void DrugComponent::insertNegativeEffect(GameEntity* entity){
	//empty method
}