#include "DrugCollisionReactionComponent.h"
#include "DrugComponent.h"
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
			object->addComponent(new SpeedDrugComponent());
			//object->addComponent(drugComponent);
		}
	}
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {
	if (isCollided){
		entity->scheduleForRemoval();
	}
	//tick() has to be called first and then receive()
	//TODO: werkt nog niet
	/*if (drugComponent == nullptr){	
		switch (entity->getEnum()){
			case Drug_Speed:
				drugComponent = new SpeedDrugComponent();
			break;
		}
	}*/

	//TODO delete entity with this collision
	//entity->scheduleForRemoval();
}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
