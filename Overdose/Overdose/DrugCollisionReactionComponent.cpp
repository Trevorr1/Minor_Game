#include "DrugCollisionReactionComponent.h"

using namespace overdose;
using namespace std;

DrugCollisionReactionComponent::DrugCollisionReactionComponent()
{
}


DrugCollisionReactionComponent::~DrugCollisionReactionComponent()
{
}

void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {
	if (entity->getEnum() == DrugAddict){
		printf("Yooooo \n");
	}
}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
