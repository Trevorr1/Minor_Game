#include "QuitOnClickComponent.h"
#include "SDL.h"

using namespace overdose;


QuitOnClickComponent::QuitOnClickComponent()
{
}


QuitOnClickComponent::~QuitOnClickComponent()
{
}


std::string QuitOnClickComponent::getComponentID(){
	return "QuitOnClickComponent";
}

void QuitOnClickComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	if (message == ClickableComponent_CLICK) {
		m_clicked = true;
	}
}

void QuitOnClickComponent::tick(float dt, GameEntity *entity) {
	if (m_clicked) {
		SDL_Event user_event;

		user_event.type = SDL_QUIT;
		user_event.user.code = 2;
		user_event.user.data1 = NULL;
		user_event.user.data2 = NULL;
		SDL_PushEvent(&user_event);
	}
}
