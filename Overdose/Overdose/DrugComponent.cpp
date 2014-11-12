#include "DrugComponent.h"
#include "GameEntity.h"



using namespace overdose;

DrugComponent::DrugComponent()
{
	previous_speedX = -999;
	timer_start = NULL;
	surface = LevelManager::getInstance().getCurrentLevel()->getSurface();
}


DrugComponent::~DrugComponent()
{
	surface = NULL;
	std::cout << "speed ervoor: " << entity->getMovementSpeed() << std::endl;
	entity->setSpeedX(previous_speedX);
	std::cout << "speed erna: " << entity->getMovementSpeed() << std::endl;
}

void DrugComponent::init(GameEntity* entity)
{
	this->entity = entity;
}

void DrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void DrugComponent::tick(float dt, GameEntity *entity) {
	if (timer_start == NULL){
		timer_start = getTimer_Start();
	}

	if (previous_speedX == -999){
		previous_speedX = entity->getMovementSpeed();
	}

	int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	int drug_effect_ms = getDrugEffectMs();

	// drug timer checker
	if (timer_end < drug_effect_ms){
		float speed_drug = getDrugSpeed_X();
		entity->setSpeedX(previous_speedX * speed_drug);
		//std::cout << "Time: " << timer_end << " ms" << std::endl;
	}
	else{
		//entity->setSpeedX(previous_speedX);
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