#include "DrugDropComponent.h"
#include "GameEntityFactory.h"
#include "LevelManager.h"
using namespace overdose;



void DrugDropComponent::tick(float dt, GameEntity *entity) {


}

void DrugDropComponent::init(GameEntity* entity) {
	m_Entity = entity;
}

void DrugDropComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

	if (message == HealthComponent_HEALTH_DECREASED && m_Entity->getHealth() != 0) {

		if (m_DropToggle) {
			GameEntity* drug = getRandomDrug();
			drug->setPosX(m_Entity->getPosX() + 50);
			drug->setPosY(m_Entity->getPosY() + 10);

			LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(drug);
		}
		
		m_DropToggle = !m_DropToggle;

	

	}

}


void DrugDropComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){

}

string DrugDropComponent::getComponentID() {
	return "DrugDropComponent";
}

GameEntity* DrugDropComponent::getRandomDrug() {
	vector<eGameEntity> options{ Drug_XTC, Drug_Marijuana };

	int dice = rand() % options.size();

	return GameEntityFactory::getInstance().getGameEntity(options.at(dice));
}