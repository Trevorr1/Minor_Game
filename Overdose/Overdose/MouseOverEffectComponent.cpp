#pragma once
#include "MouseOverEffectComponent.h"

using namespace overdose;

void MouseOverEffectComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}


void MouseOverEffectComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void MouseOverEffectComponent::tick(float dt, GameEntity *entity) {

	MouseCoordinate co = InputManager::getInstance().getMouseCoordinates();

	if (isMouseHover(entity, co.x, co.y)) {

		float x = entity->getPosX();
		float lineTopY = entity->getPosY() - 1;
		float width = entity->getWidth();

		// Line Top
		DrawManager::getInstance().getLevelSurface()->Line(x - 1, lineTopY, x + width, lineTopY, Pixel(0xff0000));
		DrawManager::getInstance().getLevelSurface()->Line(x - 1, lineTopY -1, x + width, lineTopY-1, Pixel(0xff0000));

		// Line Bottom
		DrawManager::getInstance().getLevelSurface()->Line(x - 1, lineTopY + entity->getHeight(), x + width, lineTopY + entity->getHeight(), Pixel(0xff0000));
		DrawManager::getInstance().getLevelSurface()->Line(x - 1, lineTopY + entity->getHeight() +1, x + width, lineTopY + entity->getHeight() +1, Pixel(0xff0000));

		// Line Left
		DrawManager::getInstance().getLevelSurface()->Line(x - 1, lineTopY, x -1, lineTopY + entity->getHeight(), Pixel(0xff0000));
		DrawManager::getInstance().getLevelSurface()->Line(x - 2, lineTopY, x - 2, lineTopY + entity->getHeight(), Pixel(0xff0000));

		// Line Right
		DrawManager::getInstance().getLevelSurface()->Line(x + width, lineTopY + entity->getHeight(), x + width, lineTopY, Pixel(0xff0000));
		DrawManager::getInstance().getLevelSurface()->Line(x + width +1, lineTopY + entity->getHeight(), x + width +1, lineTopY, Pixel(0xff0000));


	}
}

std::string MouseOverEffectComponent::getComponentID(){
	return "MouseOverEffectComponent";
}
