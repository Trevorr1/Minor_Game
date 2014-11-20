#include "ButtonClickableReactionComponent.h"

using namespace overdose;

ButtonClickableReactionComponent::ButtonClickableReactionComponent(levels loadScreen) {
	m_loadScreen = loadScreen;
}

std::string ButtonClickableReactionComponent::getComponentID(){
	return "ButtonClickableReactionComponent";
}

void ButtonClickableReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (message == ClickableComponent_CLICK) {
		m_clicked = true;
	}
}

void ButtonClickableReactionComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {

}

void ButtonClickableReactionComponent::tick(float dt, GameEntity *entity) {
	if (m_clicked) {
		LevelManager::getInstance().createLevel(m_loadScreen);
		m_clicked = false;
	}
}
