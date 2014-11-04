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
			entity->setFalling(true); // was comminted out, don't know why I put it back in but if there are bugs with jumping we know why - Trev
			entity->setJumpingSpeed(-1200.0f);
		}

	}

	// spel is te moeilijk voor Antoine, cheat code zodat hij ook het winscherm kan zien.
	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_F1)) {
		LevelManager::getInstance().getCurrentLevel()->setGameWon();
	}
}

std::string PlayerInputComponent ::getComponentID(){
	return "PlayerInputComponent";
}