#include "PlayerInputComponent.h"


using namespace overdose;

void  PlayerInputComponent::receive(Component &component, int message) {

}

void  PlayerInputComponent::tick(GameEntity &entity) {

	int keyDown = InputManager::getInstance()->getLastKeyPress();

	//79 right arrow
	//80 left arrow
	//-1 none
	switch (keyDown) {
	case -1:
		entity.setSpeedX(0);
		break;
	case 79:
		if (entity.getSpeedX() > 0) {
			entity.setSpeedX(entity.getSpeedX() * -1);
		}
		break;
	case 80:
		if (entity.getSpeedX() < 0) {
			entity.setSpeedX(entity.getSpeedX() * -1);
		}
		break;

	}

}
