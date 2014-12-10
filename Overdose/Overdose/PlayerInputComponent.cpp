#include "PlayerInputComponent.h"
#include <math.h>


using namespace overdose;

void  PlayerInputComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

	//If NegativeXTCComponent is initialized and destructed, reverse the keys.
	if (message == NegativeXTCComponent_REVERSE_KEYS){
		reverseKeys = !reverseKeys;
	}
}


void PlayerInputComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void  PlayerInputComponent::tick(float dt, GameEntity *entity)
{
	float accGrowth = 0.09f;
	float speedX = entity->getSpeedX();
	float moveSpeedX = entity->getMovementSpeed();

	float accX = entity->getAcclX();


	int left = SDL_SCANCODE_LEFT;// dit mag ook in de init denk ik
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


	if (InputManager::getInstance().isKeyPressed(rightPressed) && InputManager::getInstance().isKeyPressed(leftPressed))
	{
		entity->setSpeedX(0);
		entity->resetAcclX();
	}
	else if (InputManager::getInstance().isKeyPressed(rightPressed)) 
	{
		if (accX < 0)
		{
			entity->resetAcclX();
			accX = entity->getAcclX();
		}
		if (accX < moveSpeedX)
		{
			accX += moveSpeedX * accGrowth;
		}
		else
		{
			accX = moveSpeedX;
		}

		entity->setAcclX(accX);
		entity->setSpeedX(accX);


		// old code
		//if (speedX < 0) 
		//{
		//	entity->setSpeedX(-speedX);
		//}
		//if (speedX == 0) 
		//{
		//	//entity->resetAcclX();
		//	entity->setSpeedX(moveSpeedX);
		//}
	}
	else if (InputManager::getInstance().isKeyPressed(leftPressed))
	{
		if (accX > 0)
		{
			entity->resetAcclX();
			accX = entity->getAcclX();
		}
		if (accX > -moveSpeedX)
		{
			accX -= moveSpeedX * accGrowth;
		}
		else
		{
			accX = -moveSpeedX;
		}
		
		entity->setAcclX(accX);
		entity->setSpeedX(accX);

		// old code
		/*if (speedX > 0)
		{
			entity->setSpeedX(-speedX);
		}
		if (speedX == 0)
		{
			entity->setSpeedX(-moveSpeedX);
		}*/
	}
	else
	{
		entity->setSpeedX(0);
		entity->resetAcclX();
	}

	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_SPACE)) {
		if (!entity->isJumping())
		{
 			entity->resetGravity();
			entity->setJumping(true);
			entity->setFalling(true);
			entity->setJumpingSpeed(-700.0f);
		}

	}

	// spel is te moeilijk voor Antoine, cheat code zodat hij ook het winscherm kan zien.
	if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_F1)) {
		LevelManager::getInstance().getCurrentLevel()->setGameWon();
	}
	if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_F5)) {
		LevelManager::getInstance().getCurrentLevel()->setReloadLevel();
	}
}

std::string PlayerInputComponent::getComponentID(){
	return "PlayerInputComponent";
}