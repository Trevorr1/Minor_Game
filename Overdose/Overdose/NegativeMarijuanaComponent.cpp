#include "NegativeMarijuanaComponent.h"

using namespace overdose;

NegativeMarijuanaComponent::NegativeMarijuanaComponent()
{
	drug_speedX = 1.0f;
	drug_effect_ms = 1000 * 3;
}


NegativeMarijuanaComponent::~NegativeMarijuanaComponent()
{
	printf("deleted NegativeMarijuanaComponent \n");
}

void NegativeMarijuanaComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
}

void NegativeMarijuanaComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void NegativeMarijuanaComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

float NegativeMarijuanaComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int NegativeMarijuanaComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string NegativeMarijuanaComponent::getComponentID(){
	return "NegativeSpeedDrugComponent";
}
