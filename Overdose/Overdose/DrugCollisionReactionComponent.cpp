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
		if (object->getEnum() == DrugAddict){
			//printf("Player collided with this drug \n");
			isCollided = true;
		}
}


void DrugCollisionReactionComponent::tick(float dt, GameEntity *entity) {
	if (isCollided){
		//entity->setPosX(entity->getPosX() + 50);
		isCollided = false;
		//entity->addComponent(new DrugComponent());
		GameEntity *m_player = LevelManager::getInstance()->getCurrentLevel()->getPlayerEntity();
		m_player->addComponent(new DrugComponent());
		//delete entity;
	}
}

std::string DrugCollisionReactionComponent::getComponentID(){
	return "DrugCollisionReactionComponent";
}
