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
}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
