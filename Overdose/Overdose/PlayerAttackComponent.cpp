#include "PlayerAttackComponent.h"

using namespace overdose;
PlayerAttackComponent::PlayerAttackComponent()
{
	attacking = false;
}


PlayerAttackComponent::~PlayerAttackComponent()
{
}

void PlayerAttackComponent::tick(GameEntity &entity)
{
	if (attacking)
		entity.broadcast(this, 45, nullptr); //player attacking
}

void PlayerAttackComponent::receive(Component *subject, int message, GameEntity *object)
{
	if (message == 44)
	{
		//attacking
		attacking = true;
	}
	else
	{
		attacking = false;
	}
}


