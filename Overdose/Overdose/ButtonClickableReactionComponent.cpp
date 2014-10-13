#include "ButtonClickableReactionComponent.h"

using namespace overdose;

ButtonClickableReactionComponent::ButtonClickableReactionComponent(levels loadScreen) {
	m_loadScreen = loadScreen;
}


void ButtonClickableReactionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (message == ClickableComponent_CLICK) {
		m_clicked = true;
	}
}

void ButtonClickableReactionComponent::tick(float dt, GameEntity *entity) {
	if (m_clicked) {
		LevelManager::getInstance()->createLevel(m_loadScreen);
		m_clicked = false;
	}
}
