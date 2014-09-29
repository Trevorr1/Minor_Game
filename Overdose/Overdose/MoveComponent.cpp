#include "stdafx.h"

using namespace overdose;

void  MoveComponent::receive(Component &component, int message) {

}

void  MoveComponent::tick(GameEntity &entity) {

	float posX = entity.getPosX();
	float posY = entity.getPosY();
	float speedX = entity.getSpeedX();
	float speedY = entity.getSpeedY();

	
	entity.setPosX(posX + speedX);
	entity.setPosY(posY + speedY);

}

