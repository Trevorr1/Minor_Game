#include "NegativeSpeedDrugComponent.h"

using namespace overdose;

NegativeSpeedDrugComponent::NegativeSpeedDrugComponent()
{
	drug_speedX = -1.0f;
	drug_effect_ms = 1000 * 3;
}


NegativeSpeedDrugComponent::~NegativeSpeedDrugComponent()
{
	printf("deleted NegativeSpeedDrugComponent");
}

void NegativeSpeedDrugComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
}

void NegativeSpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

float NegativeSpeedDrugComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int NegativeSpeedDrugComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string NegativeSpeedDrugComponent::getComponentID(){
	return "NegativeSpeedDrugComponent";
}