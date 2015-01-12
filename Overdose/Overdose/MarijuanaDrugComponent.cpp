#include "MarijuanaDrugComponent.h"

using namespace overdose;

MarijuanaDrugComponent::MarijuanaDrugComponent()
{
	drug_speedX = 0.5f;
	drug_effect_ms = 1000 * 5;
}


MarijuanaDrugComponent::~MarijuanaDrugComponent()
{
	printf("Deleted MarijuanaDrugComponent \n");
}

void MarijuanaDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	
}

void MarijuanaDrugComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {
}

void MarijuanaDrugComponent::insertNegativeEffect(GameEntity* entity)
{
	//entityForNegativeEffect->push_back(entity);
	entity->delayedAddComponent(new NegativeMarijuanaComponent());
}

float MarijuanaDrugComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int MarijuanaDrugComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string MarijuanaDrugComponent::getComponentID(){
	return "MarijuanaDrugComponent";
}

void MarijuanaDrugComponent::insertParticleEffect(GameEntity* entity, double incr_particle_timer){
	entity->delayedAddComponent(new ParticleComponent(SmileyFace, 0.1, incr_particle_timer / 1000, 0.1));
}
