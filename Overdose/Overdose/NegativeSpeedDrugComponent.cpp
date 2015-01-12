#include "NegativeSpeedDrugComponent.h"

using namespace overdose;

NegativeSpeedDrugComponent::NegativeSpeedDrugComponent()
{
	drug_speedX = 0.2f;
	drug_effect_ms = 1000 * 3;
}


NegativeSpeedDrugComponent::~NegativeSpeedDrugComponent()
{
	printf("deleted NegativeSpeedDrugComponent \n");
}

void NegativeSpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void NegativeSpeedDrugComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

float NegativeSpeedDrugComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int NegativeSpeedDrugComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string NegativeSpeedDrugComponent::getComponentID(){
	return "NegativeSpeedDrugComponent";
}

void NegativeSpeedDrugComponent::insertParticleEffect(GameEntity* entity, double incr_particle_timer){
	entity->delayedAddComponent(new ParticleComponent(SadFace, 0.1, incr_particle_timer / 1000, 0.1));
}
