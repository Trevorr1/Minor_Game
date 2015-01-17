#include "SpeedDrugComponent.h"
#include "NegativeSpeedDrugComponent.h"
//#include "GameEntity.h"


using namespace overdose;

SpeedDrugComponent::SpeedDrugComponent()
{
	//previous_speedX = getPrevious_SpeedX();
	drug_speedX = 2.5f;
	drug_effect_ms = 1000 * 3;
	//timer_start = NULL;
}


SpeedDrugComponent::~SpeedDrugComponent()
{
	printf("deleted SpeedDrugComponent \n");
}

void SpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void SpeedDrugComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {
}


void SpeedDrugComponent::insertNegativeEffect(GameEntity* entity)
{
	//entityForNegativeEffect->push_back(entity);
	entity->delayedAddComponent(new NegativeSpeedDrugComponent());
}

float SpeedDrugComponent::getDrugSpeed_X(){
	return drug_speedX;
}

int SpeedDrugComponent::getDrugEffectMs(){
	return drug_effect_ms;
}

std::string SpeedDrugComponent::getComponentID(){
	return "SpeedDrugComponent";
}
void SpeedDrugComponent::insertParticleEffect(GameEntity* entity, double incr_particle_timer){
	entity->delayedAddComponent(new ParticleComponent(SmileyFace, 0.1, incr_particle_timer / 1000, 0.1));
}
