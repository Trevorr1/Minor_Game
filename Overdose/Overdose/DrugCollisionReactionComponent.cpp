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
	//if (object != nullptr)
	//	if (object->getEnum() == DrugAddict){
	//		//printf("Player collided with this drug \n");
	//		isCollided = true;
	//	}
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {
	if (entity->getCollideBottom() || entity->getCollideTop() || entity->getCollideLeft() || entity->getCollideRight() ||
		entity->getReactTop() || entity->getReactBottom() || entity->getReactLeft() || entity->getReactRight())
	{
		isCollided = true;
		// aaaaahhhhhh i hate myself for this method - trev
		entity->setAllFalse();
	}
	
	if (isCollided){
		entity->setPosX(entity->getPosX() + 50);
		isCollided = false;
		//entity->addComponent(new DrugComponent());
		//delete entity;
	}
}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
