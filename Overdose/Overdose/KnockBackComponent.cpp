#include "KnockBackComponent.h"

using namespace overdose;

KnockBackComponent::KnockBackComponent()
{
}


KnockBackComponent::~KnockBackComponent()
{
}

void KnockBackComponent::receive(Component *subject, ComponentMessage message, GameEntity *object){
	
	switch (object->getEnum()) {
		// fallthrough
	case Drug_Marijuana:
	case Drug_Speed:
	case Drug_XTC:
	case Environment:
	case Grass:
	case Flag:
		return;
	
	}


	if (message == CollissionComponent_COLLISION_LEFT || message == CollissionComponent_REACTION_LEFT) {
		knockBackToRight = true;
		printf("Knocking Back to the right\n");
	}

	if (message == CollissionComponent_COLLISION_RIGHT || message == CollissionComponent_REACTION_RIGHT) {
		knockBackToLeft = true;
		printf("Knocking back to the left\n");
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

}


std::string KnockBackComponent::getComponentID(){
	return "KnockBackComponent";
}