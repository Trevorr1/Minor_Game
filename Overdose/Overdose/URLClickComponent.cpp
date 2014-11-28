#include "URLClickComponent.h"
#include <windows.h>

using namespace overdose;
URLClickComponent::URLClickComponent(std::string URL)
{
	m_URL = URL;
}


URLClickComponent::~URLClickComponent()
{
}

std::string URLClickComponent::getComponentID(){
	return "URLClickComponent";
}

void URLClickComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (message == ClickableComponent_CLICK) {
		m_clicked = true;
		//Open URL
		ShellExecute(NULL, "open", m_URL.c_str(),
			NULL, NULL, SW_SHOWNORMAL);
	}
}

void URLClickComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {

}

void URLClickComponent::tick(float dt, GameEntity *entity) {
	if (m_clicked) {
		m_clicked = false;
	}
}