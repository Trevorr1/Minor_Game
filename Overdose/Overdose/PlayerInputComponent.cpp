#include "PlayerInputComponent.h"


using namespace overdose;

void  PlayerInputComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

	//If NegativeXTCComponent is initialized and destructed, reverse the keys.
	if (message == NegativeXTCComponent_REVERSE_KEYS){
		reverseKeys = !reverseKeys;
}
}


void PlayerInputComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void  PlayerInputComponent::tick(float dt, GameEntity *entity) {

	float speedX = entity->getSpeedX();

	int left = SDL_SCANCODE_LEFT;
	int right = SDL_SCANCODE_RIGHT;

	int leftPressed = 0, rightPressed = 0;

	if (!reverseKeys){
		leftPressed = left;
		rightPressed = right;
	}
	else{
		leftPressed = right;
		rightPressed = left;
	}


	if (InputManager::getInstance().isKeyPressed(rightPressed) && InputManager::getInstance().isKeyPressed(leftPressed)) {
		entity->setSpeedX(0);
	}
	else if (InputManager::getInstance().isKeyPressed(rightPressed)) {
		if (speedX < 0) {
			entity->setSpeedX((float)speedX);
		}
		if (speedX == 0) {
			entity->setSpeedX(entity->getMovementSpeed());
		}
	}
	else if (InputManager::getInstance().isKeyPressed(leftPressed)) {
		if (speedX > 0){
			entity->setSpeedX((float)speedX * -1);
		}
		if (speedX == 0) {
			entity->setSpeedX(-entity->getMovementSpeed());
		}
	}
	else 
	{
		entity->setSpeedX(0);
	}

	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_SPACE)) {
		if (!entity->isJumping())
		{
			entity->setJumping(true);
			entity->setFalling(true);
			entity->setJumpingSpeed(-1200.0f);
		}

	}

	// spel is te moeilijk voor Antoine, cheat code zodat hij ook het winscherm kan zien.
	if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_F1)) {
		LevelManager::getInstance().getCurrentLevel()->setGameWon();
	}
}

std::string PlayerInputComponent ::getComponentID(){
	return "PlayerInputComponent";
}