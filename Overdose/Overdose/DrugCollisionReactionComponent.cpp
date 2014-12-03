#include "DrugCollisionReactionComponent.h"
#include "DrugComponent.h"
#include "SpeedDrugComponent.h"
#include "MarijuanaDrugComponent.h"
#include "XTCDrugComponent.h"
#include "LevelManager.h"


using namespace overdose;
using namespace std;

DrugCollisionReactionComponent::DrugCollisionReactionComponent()
{
}


DrugCollisionReactionComponent::~DrugCollisionReactionComponent()
{
	//Delete the drug component when Player didn't pick up drug
	if (drugComponent != nullptr && !isCollided){
		delete drugComponent;
	}
}

void DrugCollisionReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (object != nullptr)
	{
	if (object->getEnum() == Player){
		//printf("Player collided with this drug \n");
		isCollided = true;
		//bool inList = false;
		for (unsigned int i = 0; i < object->getComponentList()->size(); i++)
		{
			//if (typeid(object->getComponentList()->at(i)) ==  typeid(DrugComponent))
			if (dynamic_cast<DrugComponent*>(object->getComponentList()->at(i)) != nullptr)
			{
				//inList = true;
				object->setMovementSpeed(190.0f);///////////////////////this is not pretty but needs to be fixed god hates me!!!!
				object->removeComponent(object->getComponentList()->at(i)->getComponentID());
				//delete object->getComponentList()->at(i);
			}
		}
		/*if (!inList)
		{*/
			object->addComponent(drugComponent);
		//}
	}
}
}

void DrugCollisionReactionComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {
	//delete this Drug, when collided
	if (isCollided){
		entity->scheduleForRemoval();
	}

	if (drugComponent == nullptr){	
		switch (entity->getEnum()){
			case Drug_Speed:
				drugComponent = new SpeedDrugComponent();
			break;
			case Drug_Marijuana:
				drugComponent = new MarijuanaDrugComponent();
			break;
			case Drug_XTC:
				drugComponent = new XTCDrugComponent();
			break;
		}
	}

}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
