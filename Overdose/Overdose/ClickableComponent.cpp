#include "ClickableComponent.h"
#include "SoundManager.h"
#include "LevelManager.h"
#include <iostream>
using namespace overdose;

void ClickableComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void ClickableComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void ClickableComponent::tick(float dt, GameEntity *entity) {
	//use these camera position, if Tutorial is on levelSurface
	int cameraSurfaceX = LevelManager::getInstance().getCurrentLevel()->getCamera()->getPositionX();
	int cameraSurfaceY = LevelManager::getInstance().getCurrentLevel()->getCamera()->getPositionY();

	MouseClick click = InputManager::getInstance().getLastMouseClick();

	//(isMouseHover(entity, click.x, click.y) not needed for cameraSurface)
	if (click.x && click.y && 
		click.x + cameraSurfaceX < entity->getPosX() + entity->getWidth() && click.x + cameraSurfaceX > entity->getPosX() &&
		click.y + cameraSurfaceY > entity->getPosY() && click.y + cameraSurfaceY < entity->getPosY() + entity->getHeight()) {
		//std::cout << "clicked" << std::endl;
		entity->broadcast(this, ClickableComponent_CLICK, entity);

		SoundManager::getInstance().PlaySound(Click);
	}
}

std::string ClickableComponent::getComponentID(){
	return "ClickableComponent";
}
