#include "DrugCollisionReactionComponent.h"
#include "DrugComponent.h"
#include "LevelManager.h"


using namespace overdose;
using namespace std;

DrugCollisionReactionComponent::DrugCollisionReactionComponent()
{
}


DrugCollisionReactionComponent::~DrugCollisionReactionComponent()
{
}

void DrugCollisionReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (object != nullptr)
	if (object->getEnum() == Player){
		//printf("Player collided with this drug \n");
		isCollided = true;
		bool inList = false;
		for (unsigned int i = 0; i < object->getComponentList()->size(); i++)
		{
			//if (typeid(object->getComponentList()->at(i)) ==  typeid(DrugComponent))
			if (dynamic_cast<DrugComponent*>(object->getComponentList()->at(i)) != NULL)
			{
				inList = true;
			}
		}
		if (!inList)
		{
			object->addComponent(new DrugComponent());
		}
	}
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {

}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
