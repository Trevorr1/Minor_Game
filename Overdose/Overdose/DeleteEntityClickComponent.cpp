#include "DeleteEntityClickComponent.h"

using namespace overdose;

DeleteEntityClickComponent::DeleteEntityClickComponent()
{
}


DeleteEntityClickComponent::~DeleteEntityClickComponent()
{
}

std::string DeleteEntityClickComponent::getComponentID(){
	return "DeleteEntityClickComponent";
}

void DeleteEntityClickComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (message == ClickableComponent_CLICK) {
		m_clicked = true;
	}
}


void DeleteEntityClickComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

void DeleteEntityClickComponent::tick(float dt, GameEntity *entity) {
	if (m_clicked) {
		std::cout << "DeleteEntityClickComponent delete entity" << std::endl;
		entity->scheduleForRemoval(); //this removal only works when in getEntities list in level.
		m_clicked = false;
	}
}