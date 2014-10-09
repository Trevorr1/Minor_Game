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
	//entity.broadcast
}

void PlayerAttackComponent::receive(Component &component, int message)
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


