#include "FocusPointerComponent.h"

using namespace overdose;


FocusPointerComponent::FocusPointerComponent(GameEntity* entity, CursorColor color)
{
	string str = "";

	switch (color){
	case YELLOW:
		str = "assets/sprites/Tutorial/cursor_down_yellow.png";
		break;
	case RED:
		str = "assets/sprites/Tutorial/cursor_down_red.png";
		break;
	default:
		str = "assets/sprites/Tutorial/cursor_down_yellow.png";
		break;
	}
	

	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0'; // don't forget the terminating 0

	// don't forget to free the string after finished using it

	tutorial = new GameEntity(FocusPointer);

	std::map<eAnimationState, Animation*>* animations;
	DrawComponent* animation = nullptr;
	animations = new std::map<eAnimationState, Animation*>();
	animations->insert({ Default, new Animation(writable, 3, 3) });
	animation = new DrawComponent(animations);
	animation->setAnimation(Default);//set starting animation
	tutorial->addComponent(animation);

	LevelManager::getInstance().getCurrentLevel()->scheduleEntityForInsertion(tutorial);

	delete[] writable;

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
