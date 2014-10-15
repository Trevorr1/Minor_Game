#include "DrugComponent.h"
#include "GameEntity.h"



using namespace overdose;

DrugComponent::DrugComponent()
{
	timer_start = std::clock();
}


DrugComponent::~DrugComponent()
{
}

void DrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void DrugComponent::tick(float dt, GameEntity *entity) {
	float drugSpeed = 10;
	float posX = entity->getPosX();
	float posY = entity->getPosY();
	float speedX = entity->getSpeedX() + drugSpeed;
	float speedY = entity->getSpeedY() + drugSpeed;

	//entity->setPosX(posX + speedX);
	//entity->setPosY(posY + speedY);

	entity->setSpeedX(drugSpeed);

	int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	int drug_effect_ms = 1000 * 10;

	// delete this component if drug effect timer is over
	if (timer_end > drug_effect_ms){
		std::cout << "Magic" << std::endl;
		//TODO Delete this drug component of gameEntity
		entity->removeComponent(getComponentID());
	}
	else{
		//std::cout << "Time: " << timer_end << " ms" << std::endl;
	}
}

std::string DrugComponent::getComponentID(){
	return "DrugComponent";
}
