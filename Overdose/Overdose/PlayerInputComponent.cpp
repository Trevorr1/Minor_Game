#include "PlayerInputComponent.h"


using namespace overdose;

void  PlayerInputComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void  PlayerInputComponent::tick(float dt, GameEntity *entity) {

	float speedX = entity->getSpeedX();


	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_RIGHT) && InputManager::getInstance().isKeyPressed(SDL_SCANCODE_LEFT)) {
		entity->setSpeedX(0);
	}
	else if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_RIGHT)) {
		if (speedX < 0) {
			entity->setSpeedX((float)speedX * -1);
		}
		if (speedX == 0) {
			entity->setSpeedX(entity->getMovementSpeed());
		}
	}
	else if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_LEFT)) {
		if (speedX > 0){
			entity->setSpeedX((float)speedX * -1);
		}
		if (speedX == 0) {
			entity->setSpeedX(-entity->getMovementSpeed());
		}
	}
	else {
		entity->setSpeedX(0);
	}

	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_SPACE)) {
		if (!entity->isJumping())
		{
			entity->setJumping(true);
			entity->setFalling(true);
			entity->setJumpingSpeed(-1.6);
			entity->setJumpingSpeed(-1200.0f);
		}

	}
}

std::string PlayerInputComponent ::getComponentID(){
	return "PlayerInputComponent";
}