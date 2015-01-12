#include "TutorialClickableComponent.h"
#include "SoundManager.h"
#include "LevelManager.h"
#include <iostream>

using namespace overdose;

void TutorialClickableComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void TutorialClickableComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void TutorialClickableComponent::tick(float dt, GameEntity *entity) {
	
	//use these camera position, if Tutorial is on levelSurface
	int cameraSurfaceX = LevelManager::getInstance().getCurrentLevel()->getCamera()->getPositionX();
	int cameraSurfaceY = LevelManager::getInstance().getCurrentLevel()->getCamera()->getPositionY();
	
	MouseClick click = InputManager::getInstance().getLastMouseClick();

	//Close button in image (isMouseHover(entity, click.x, click.y) not needed for cameraSurface)
	if (click.x && click.y &&
		click.x + cameraSurfaceX < entity->getPosX() + entity->getWidth() && click.x + cameraSurfaceX > entity->getPosX() + entity->getWidth() - 15 &&
		click.y + cameraSurfaceY > entity->getPosY() && click.y + cameraSurfaceY < entity->getPosY() + 15)
	{
		entity->scheduleForRemoval();
		SoundManager::getInstance().PlaySound(Click);
	}
	//Next button in image (isMouseHover(entity, click.x, click.y) not needed for cameraSurface)
	else if (click.x && click.y &&
		(click.x + cameraSurfaceX) < entity->getPosX() + entity->getWidth() - 10 && (click.x + cameraSurfaceX) > entity->getPosX() + entity->getWidth() - 160 &&
		click.y + cameraSurfaceY < entity->getPosY() + entity->getHeight() - 5 && click.y + cameraSurfaceY > entity->getPosY() + entity->getHeight() - 50)
	{
		entity->broadcast(this, TutorialClickableComponent_CLICK, entity);
		SoundManager::getInstance().PlaySound(Click);
	}

}

std::string TutorialClickableComponent::getComponentID(){
	return "TutorialClickableComponent";
}
