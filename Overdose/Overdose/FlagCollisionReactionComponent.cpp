#include "FlagCollisionReactionComponent.h"
#include "LevelManager.h"
using namespace overdose;

FlagCollisionReactionComponent::FlagCollisionReactionComponent()
{

}


FlagCollisionReactionComponent::~FlagCollisionReactionComponent()
{

}


void FlagCollisionReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object){

	if (object != nullptr){
		if (object->getEnum() == Player){
			LevelManager::getInstance().getCurrentLevel()->setGameWon();
		}
	}
}


void FlagCollisionReactionComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){}

void FlagCollisionReactionComponent::tick(float dt, GameEntity *entity){

}

std::string FlagCollisionReactionComponent::getComponentID(){
	return "FlagCollisionReactionComponent";
}