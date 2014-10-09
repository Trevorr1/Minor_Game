#include "PlayerInputComponent.h"


using namespace overdose;

void  PlayerInputComponent::receive(Component *subject, int message, GameEntity *object) {

}

void  PlayerInputComponent::tick(GameEntity *entity) {

	int keyDown = InputManager::getInstance()->getLastKeyPress();

	//79 right arrow
	//80 left arrow
	//-1 none
	int speedX = entity->getSpeedX();

	switch (keyDown) {
	case -1:
		entity->setSpeedX(0);
		break;
	case 79:
		if (speedX > 0) {
			entity->setSpeedX(speedX * -1);
		}
		if ((int)speedX == 0) {
			entity->setSpeedX(2);
		}
		break;
	case 80:
		if (speedX < 0) {
			entity->setSpeedX(speedX * -1);
		}
		if (speedX == 0) {
			entity->setSpeedX(-2);
		}
		break;

	}

}
