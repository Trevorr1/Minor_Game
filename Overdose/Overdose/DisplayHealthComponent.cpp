#include "DisplayHealthComponent.h"
#include "DrawManager.h"
using namespace overdose;

DisplayHealthComponent::DisplayHealthComponent() {

}

void DisplayHealthComponent::tick(float dt, GameEntity *entity) {

	char health[4];

	strcpy_s(health, sizeof(health), std::to_string(entity->getHealth()).c_str());


	DrawManager::getInstance().getLevelSurface()->WriteText(health, entity->getPosX() + (entity->getWidth() / 2), entity->getPosY() -  20);

}

void DisplayHealthComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}


void DisplayHealthComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){

}

string DisplayHealthComponent::getComponentID() {
	return "DisplayHealthComponent";
}