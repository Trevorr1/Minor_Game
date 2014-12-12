#include "FocusPointerComponent.h"

using namespace overdose;


FocusPointerComponent::FocusPointerComponent(GameEntity* entity)
{
	tutorial = new GameEntity(FocusPointer);

	std::map<eAnimationState, Animation*>* animations;
	DrawComponent* animation = nullptr;
	animations = new std::map<eAnimationState, Animation*>();
	animations->insert({ Default, new Animation("assets/sprites/Tutorial/cursor_down_2.png", 3, 3) });
	animation = new DrawComponent(animations);
	animation->setAnimation(Default);//set starting animation
	tutorial->addComponent(animation);

	LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(tutorial);
}


FocusPointerComponent::~FocusPointerComponent()
{
	// the tutorial entity must be called before the entity that adds this FocusPointerCompontent, to be able to delete this tutorial entity.
	// Therefore FocusPointerComponent can only be called in GameEntityFactory. 
	if (tutorial->isScheduledForRemoval() == false){// == nullptr didn't work. So check on isScheduledForRemoval(), deleted tutorial when entity dies.
		tutorial->scheduleForRemoval();
	}
	else{
	}
	std::cout << "Deleted FocusPointerComponent" << std::endl;
}

void FocusPointerComponent::tick(float dt, GameEntity *entity) {
	tutorial->setPosY(entity->getPosY()- 50);

	//set posX in the middle of the entity
	float middle = (entity->getPosX() + entity->getWidth() / 2) - (tutorial->getWidth() / 2);
	tutorial->setPosX(middle);
}
	
void FocusPointerComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	
}

void FocusPointerComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {

}

string FocusPointerComponent::getComponentID() {
	return "FocusPointerComponent";
}
