#include "ClickableComponent.h"
#include <iostream>
using namespace overdose;

void ClickableComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void ClickableComponent::tick(float dt, GameEntity *entity) {
	MouseClick click = InputManager::getInstance()->getLastMouseClick();

	if (click.x >= entity->getPosX() && click.x <= entity->getPosX() + entity->getWidth() &&
		click.y >= entity->getPosY() && click.y <= entity->getPosY() + entity->getHeight()) {

		entity->broadcast(this, ClickableComponent_CLICK, nullptr);

		std::cout << "Hit!" << std::endl;
	}
}