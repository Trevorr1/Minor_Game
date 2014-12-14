#include "AIComponent.h"

using namespace overdose;

AIComponent::AIComponent() {}

void AIComponent::tick(float dt, GameEntity *entity) {
	m_state->handle(this, entity);
}

void AIComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}


void AIComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages){

}

string AIComponent::getComponentID() {
	return "AIComponent";
}

void AIComponent::setState(unique_ptr<IFSMBoss> state) {
	m_state = std::move(state);
}