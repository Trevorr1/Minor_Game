#include "SpeedDrugComponent.h"
#include "NegativeSpeedDrugComponent.h"
//#include "GameEntity.h"


using namespace overdose;

SpeedDrugComponent::SpeedDrugComponent()
{
	//previous_speedX = getPrevious_SpeedX();
	drug_speedX = 6.0f;
	drug_effect_ms = 1000 * 5;

	entityForNegativeEffect = new std::vector<GameEntity*>();
	//timer_start = NULL;
}


SpeedDrugComponent::~SpeedDrugComponent()
{
	printf("deleted speedDrugComponent \n");
}

void SpeedDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void SpeedDrugComponent::tick(float dt, GameEntity *entity) {
	//for (int i = 0; i < entityForNegativeEffect->size(); i++)
	//{
	//	GameEntity* e = entityForNegativeEffect->at(i);
	//	e->addComponent(new NegativeSpeedDrugComponent());
	//	//entityForNegativeEffect->erase(entityForNegativeEffect->begin()+i);
	//}

	DrugComponent::tick(dt, entity);
	//if (timer_start == NULL){
	//	timer_start = getTimer_Start();
	//}

	//if (previous_speedX == getPrevious_SpeedX()){
	//	previous_speedX = entity->getSpeedX();
	//}

	//float drugSpeed = 2.0f;
	//entity->setSpeedX(drugSpeed);

	//int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	//int drug_effect_ms = 1000 * 5;

	//// drug timer checker
	//if (timer_end < drug_effect_ms){
	//	std::cout << "Time: " << timer_end << " ms" << std::endl;
	//}
	//else{
	//	entity->setSpeedX(previous_speedX);
	//	// Delete this drug component of gameEntity
	//	entity->removeComponent(getComponentID());

	//	//Delete this SpeedDrugComponent
	//	delete this;
	//}
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
