#include "TextBoxInputComponent.h"

using namespace overdose;

TextBoxInputComponent::TextBoxInputComponent()
{
	Init();
}


TextBoxInputComponent::~TextBoxInputComponent()
{
}

void TextBoxInputComponent::tick(float dt, GameEntity *entity)
{
	typedef std::map<int, std::string>::iterator iterator_type;
	for (iterator_type iterator = sdlKeyCodes->begin(); iterator != sdlKeyCodes->end(); iterator++)
	{
		if (InputManager::getInstance().isKeyPressed(iterator->first))
		{
			std::cout << iterator->second << std::endl;
		}
	}

}

void TextBoxInputComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{}


void TextBoxInputComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {
}

void TextBoxInputComponent::Init()
{
	sdlKeyCodes->insert({ SDL_SCANCODE_A, "A" });
	sdlKeyCodes->insert({ SDL_SCANCODE_B, "B" });
	sdlKeyCodes->insert({ SDL_SCANCODE_C, "C" });
	sdlKeyCodes->insert({ SDL_SCANCODE_D, "D" });
	sdlKeyCodes->insert({ SDL_SCANCODE_E, "E" });
	sdlKeyCodes->insert({ SDL_SCANCODE_F, "F" });
	sdlKeyCodes->insert({ SDL_SCANCODE_G, "G" });
	sdlKeyCodes->insert({ SDL_SCANCODE_H, "H" });
	sdlKeyCodes->insert({ SDL_SCANCODE_I, "I" });
	sdlKeyCodes->insert({ SDL_SCANCODE_J, "J" });
	sdlKeyCodes->insert({ SDL_SCANCODE_K, "K" });
	sdlKeyCodes->insert({ SDL_SCANCODE_L, "L" });
	sdlKeyCodes->insert({ SDL_SCANCODE_M, "M" });
	sdlKeyCodes->insert({ SDL_SCANCODE_N, "N" });
	sdlKeyCodes->insert({ SDL_SCANCODE_O, "O" });
	sdlKeyCodes->insert({ SDL_SCANCODE_P, "P" });
	sdlKeyCodes->insert({ SDL_SCANCODE_Q, "Q" });
	sdlKeyCodes->insert({ SDL_SCANCODE_R, "R" });
	sdlKeyCodes->insert({ SDL_SCANCODE_S, "S" });
	sdlKeyCodes->insert({ SDL_SCANCODE_T, "T" });
	sdlKeyCodes->insert({ SDL_SCANCODE_U, "U" });
	sdlKeyCodes->insert({ SDL_SCANCODE_V, "V" });
	sdlKeyCodes->insert({ SDL_SCANCODE_W, "W" });
	sdlKeyCodes->insert({ SDL_SCANCODE_X, "X" });
	sdlKeyCodes->insert({ SDL_SCANCODE_Y, "Y" });
	sdlKeyCodes->insert({ SDL_SCANCODE_Z, "Z" });

}
std::string TextBoxInputComponent::getComponentID(){
	return "TextBoxInputComponent";
}