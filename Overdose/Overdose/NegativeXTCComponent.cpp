#include "NegativeXTCComponent.h"

using namespace overdose;

NegativeXTCComponent::NegativeXTCComponent()
{
	drug_speedX = 0.2f;
	drug_effect_ms = 1000 * 3;
}


NegativeXTCComponent::~NegativeXTCComponent()
{
	entity->broadcast(this, NegativeXTCComponent_REVERSE_KEYS, entity);
	printf("deleted NegativeXTCComponent \n");
}

void NegativeXTCComponent::init(GameEntity* entity)
{
	entity->broadcast(this, NegativeXTCComponent_REVERSE_KEYS, entity);
}

void NegativeXTCComponent::tick(float dt, GameEntity *entity) {
	
	//Ugly way to initialize, but if GameEntity: delayedAddComponent init this, it crash while iterating in tick()
	if (entity !=NULL){
		this->entity = entity;
		DrugComponent::init(entity);
	}
	DrugComponent::tick(dt,entity);
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