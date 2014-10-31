#include "MarijuanaComponent.h"

using namespace overdose;

MarijuanaComponent::MarijuanaComponent()
{
	drug_speedX = 0.5f;
	drug_effect_ms = 1000 * 5;
}


MarijuanaComponent::~MarijuanaComponent()
{
	printf("deleted MarijuanaComponent \n");
	
}

void MarijuanaComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	
}

void MarijuanaComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
}

float MarijuanaComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int MarijuanaComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string MarijuanaComponent::getComponentID(){
	return "MarijuanaComponent";
}
