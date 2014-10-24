#include "XTCDrugComponent.h"

using namespace overdose;

XTCDrugComponent::XTCDrugComponent()
{
	previous_speedX = -999;
	drug_speedX = 2.5f;
	drug_effect_ms = 1000 * 10;
	timer_start = NULL;
}


XTCDrugComponent::~XTCDrugComponent()
{
	printf("deleted XTCDrugComponent \n");
	setUnvulnerability();
}

void XTCDrugComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void XTCDrugComponent::tick(float dt, GameEntity *entity) {
	//DrugComponent::tick(dt, entity);
	if (timer_start == NULL){
		timer_start = getTimer_Start();

		XTC_gameEntity = entity;
		setVulnerability();
	}

	if (previous_speedX == -999){
		previous_speedX = entity->getSpeedX();
	}

	entity->setSpeedX(getDrugSpeed_X());

	int timer_end = (std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000);
	int drug_effect_ms = getDrugEffectMs();

	// drug timer checker
	if (timer_end < drug_effect_ms){
		//std::cout << "Time: " << timer_end << " ms" << std::endl;
	}
	else{
		entity->setSpeedX(previous_speedX);
		// Delete this drug component of gameEntity
		entity->removeComponent(getComponentID());
		setUnvulnerability();

		//insertNegativeEffect(entity);
	}
}

void XTCDrugComponent::setVulnerability(){
	for (int i = 0; i < XTC_gameEntity->getComponentList()->size(); i++){
		if (XTC_gameEntity->getComponentList()->at(i)->getComponentID() == "HealthComponent"){
			XTC_gameEntity->addComponentTemporary(XTC_gameEntity->getComponentList()->at(i));
		}
	}
}

void XTCDrugComponent::setUnvulnerability(){
	XTC_gameEntity->unVulnerability = false;
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