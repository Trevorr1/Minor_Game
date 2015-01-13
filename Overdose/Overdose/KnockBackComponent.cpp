#include "KnockBackComponent.h"

using namespace overdose;

KnockBackComponent::KnockBackComponent()
{
}


KnockBackComponent::~KnockBackComponent()
{
}

void KnockBackComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{
	switch (object->getEnum()) {
		// fallthrough
	case Drug_Marijuana:
	case Drug_Speed:
	case Drug_XTC:
	case Environment:
	case Grass:
	case Flag:
	case Particle:
		return;
	}


	if (message == CollissionComponent_REACTION_LEFT) {
		knockBackToRight = true;
		//printf("Knocking Back to the right\n");
	}

	if (message == CollissionComponent_REACTION_RIGHT) {
		knockBackToLeft = true;
		//printf("Knocking back to the left\n");
	}

	if (message == CollissionComponent_REACTION_BOTTOM) {
		knockBackToTop = true;
		//printf("Knocking back to top\n");
	}
}


void KnockBackComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages)
{
	for (std::map<ComponentMessage, GameEntity*>::iterator it = messages.begin(); it != messages.end(); ++it)
	{
		switch (it->second->getEnum()) {
			// fallthrough
		case Drug_Marijuana:
		case Drug_Speed:
		case Drug_XTC:
		case Environment:
		case Grass:
		case Flag:
		case Advertisement_GameEntity:
		case Particle:
			return;
		}
		switch (it->first)
		{
		case CollissionComponent_REACTION_TOP:
			// nothing yet
			break;
		case CollissionComponent_REACTION_BOTTOM:
			knockBackToTop = true;
			//printf("Knocking back to top\n");
			break;
		case CollissionComponent_REACTION_LEFT:
			knockBackToRight = true;
			//printf("Knocking Back to the right\n");
			break;
		case CollissionComponent_REACTION_RIGHT:
			knockBackToLeft = true;
			//printf("Knocking back to the left\n");
			break;
		}
	}
}

void KnockBackComponent::tick(float dt, GameEntity *entity)
{
	if (knockBackToLeft)
	{
		entity->setPosX(entity->getPosX() - knockbackValue);
		knockBackToLeft = false;
	}

	if (knockBackToRight)
	{
		entity->setPosX(entity->getPosX() + knockbackValue);
		knockBackToRight = false;
	}

	if (knockBackToTop)
	{
		entity->resetGravity();
		entity->setSpeedY(0);
		//entity->setSpeedY(800.0f); // changed this so it would work, hate me later. - Trev
		entity->setJumpingSpeed(-700.0f);
		entity->setJumping(true);
		entity->setFalling(true);
		knockBackToTop = false;
	}

}


std::string KnockBackComponent::getComponentID(){
	return "KnockBackComponent";
}