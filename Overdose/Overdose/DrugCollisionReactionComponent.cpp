#include "DrugCollisionReactionComponent.h"
#include "SpeedDrugComponent.h"
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
	if (object->getEnum() == DrugAddict){
		//printf("Player collided with this drug \n");
		isCollided = true;
		bool inList = false;
		for (unsigned int i = 0; i < object->getComponentList()->size(); i++)
		{
			//if (typeid(object->getComponentList()->at(i)) ==  typeid(DrugComponent))
			if (dynamic_cast<SpeedDrugComponent*>(object->getComponentList()->at(i)) != NULL)
			{
				inList = true;
			}
		}
		if (!inList)
		{
			object->addComponent(new SpeedDrugComponent());
		}
	}
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {

}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
