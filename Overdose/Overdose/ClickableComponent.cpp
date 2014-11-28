#include "ClickableComponent.h"
#include "SoundManager.h"
#include <iostream>
using namespace overdose;

void ClickableComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void ClickableComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void ClickableComponent::tick(float dt, GameEntity *entity) {
	MouseClick click = InputManager::getInstance().getLastMouseClick();

	if (isMouseHover(entity, click.x, click.y)) {

		entity->broadcast(this, ClickableComponent_CLICK, entity);

		SoundManager::getInstance().PlaySound(Click);
	}
}

std::string ClickableComponent::getComponentID(){
	return "ClickableComponent";
}
