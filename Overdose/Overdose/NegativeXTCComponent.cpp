#include "NegativeXTCComponent.h"

using namespace overdose;

NegativeXTCComponent::NegativeXTCComponent()
{
	drug_speedX = 0.2f;
	drug_effect_ms = 1000 * 3;
}


NegativeXTCComponent::~NegativeXTCComponent()
{
	printf("deleted NegativeSpeedDrugComponent \n");
}

void NegativeXTCComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
}

void NegativeXTCComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

float NegativeXTCComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int NegativeXTCComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string NegativeXTCComponent::getComponentID(){
	return "NegativeXTCComponent";
}