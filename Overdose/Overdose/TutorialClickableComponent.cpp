#include "TutorialClickableComponent.h"
#include "SoundManager.h"
#include <iostream>

using namespace overdose;

void TutorialClickableComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void TutorialClickableComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void TutorialClickableComponent::tick(float dt, GameEntity *entity) {
	MouseClick click = InputManager::getInstance().getLastMouseClick();

	//Close button in image
	if (isMouseHover(entity, click.x, click.y) &&
		click.x < entity->getPosX() + entity->getWidth() && click.x > entity->getPosX() - 15 &&
		click.y > entity->getPosY() && click.y < entity->getPosY() +15)
	{
		entity->scheduleForRemoval();
		SoundManager::getInstance().PlaySound(Click);
	}
	//Next button in image
	else if (isMouseHover(entity, click.x, click.y) &&
		click.x < entity->getPosX() + entity->getWidth() - 10 && click.x > entity->getPosX() + entity->getWidth() - 160 &&
		click.y < entity->getPosY() + entity->getHeight() - 5 && click.y > entity->getPosY() + entity->getHeight() -50)
	{
		entity->broadcast(this, TutorialClickableComponent_CLICK, entity);
		SoundManager::getInstance().PlaySound(Click);
	}
}

std::string TutorialClickableComponent::getComponentID(){
	return "TutorialClickableComponent";
}
