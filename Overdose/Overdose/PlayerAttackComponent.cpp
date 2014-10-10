#include "PlayerAttackComponent.h"
#include "InputManager.h"
using namespace overdose;
PlayerAttackComponent::PlayerAttackComponent()
{

}


PlayerAttackComponent::~PlayerAttackComponent()
{
}

void PlayerAttackComponent::tick(float dt, GameEntity *entity)
{
	int keyDown = InputManager::getInstance()->getLastKeyPress();
	if (keyDown == 44)
	{
		entity->broadcast(this, Player_ATTACKING, nullptr);
	}

}

void PlayerAttackComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{

}


