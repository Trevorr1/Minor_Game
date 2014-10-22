#include "XTCDrugComponent.h"

using namespace overdose;

XTCDrugComponent::XTCDrugComponent()
{
	drug_speedX = 0.5f;
	drug_effect_ms = 1000 * 5;
}


XTCDrugComponent::~XTCDrugComponent()
{
}

void XTCDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void XTCDrugComponent::tick(float dt, GameEntity *entity) {
	DrugComponent::tick(dt, entity);
}

float XTCDrugComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int XTCDrugComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string XTCDrugComponent::getComponentID(){
	return "XTCDrugComponent";
}
