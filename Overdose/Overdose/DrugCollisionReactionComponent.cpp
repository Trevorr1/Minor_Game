#include "DrugCollisionReactionComponent.h"
#include "DrugComponent.h"


using namespace overdose;
using namespace std;

DrugCollisionReactionComponent::DrugCollisionReactionComponent()
{
}


DrugCollisionReactionComponent::~DrugCollisionReactionComponent()
{
}

void DrugCollisionReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (object->getEnum() == DrugAddict){
		//printf("Player collided with this drug \n");
		isCollided = true;
		object->addComponent(new DrugComponent());
	}
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {
	if (isCollided){
		isCollided = false;
		entity->setPosX(entity->getPosX() + 50);
		//delete entity;
	}
}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}