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
	Surface *surface = DrawManager::getInstance().getLevelSurface();
	/*surface->WriteText("test", (int)entity->getPosX(), (int)entity->getPosY());*/

	if (clicked && !text_typed)
	{
		typedef std::map<int, std::string>::iterator iterator_type;
		for (iterator_type iterator = sdlKeyCodes->begin(); iterator != sdlKeyCodes->end(); iterator++)
		{
			if (InputManager::getInstance().isKeyPressedOnce(iterator->first))
			{
				std::cout << "Letter pressed: " + iterator->second << std::endl;
				if (iterator->second == "BACKSPACE")
				{
					if (toWrite.size() > 0)
						toWrite.erase(toWrite.end() - 1);
				}
				else if (iterator->second == "RETURN")
				{
					clicked = false;
					entity->broadcast(this, ComponentMessage::TextBoxInputComponent_TEXT_TYPED, entity);
				}
				else if (toWrite.size() < 10)
					toWrite.append(iterator->second);
			}
		}
	}
	const char *t = toWrite.c_str();
	char *chars = const_cast<char*>(t);
	surface->WriteText(chars, (int)entity->getPosX(), (int)entity->getPosY());

}

void TextBoxInputComponent::receive(Component *subject, ComponentMessage message, GameEntity *object)
{
	if (object->getEnum() == eGameEntity::TextBox)
	{
		if (message == ClickableComponent_CLICK)
		{
			clicked = true;
		}
		else if (message = TextBoxInputComponent_TEXT_TYPED)
		{
			text_typed = true;
		}
	}
}


void TextBoxInputComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {
}

void TextBoxInputComponent::Init()
{
	sdlKeyCodes->insert({ SDL_SCANCODE_A, "a" });
	sdlKeyCodes->insert({ SDL_SCANCODE_B, "b" });
	sdlKeyCodes->insert({ SDL_SCANCODE_C, "c" });
	sdlKeyCodes->insert({ SDL_SCANCODE_D, "d" });
	sdlKeyCodes->insert({ SDL_SCANCODE_E, "e" });
	sdlKeyCodes->insert({ SDL_SCANCODE_F, "f" });
	sdlKeyCodes->insert({ SDL_SCANCODE_G, "g" });
	sdlKeyCodes->insert({ SDL_SCANCODE_H, "h" });
	sdlKeyCodes->insert({ SDL_SCANCODE_I, "i" });
	sdlKeyCodes->insert({ SDL_SCANCODE_J, "j" });
	sdlKeyCodes->insert({ SDL_SCANCODE_K, "k" });
	sdlKeyCodes->insert({ SDL_SCANCODE_L, "l" });
	sdlKeyCodes->insert({ SDL_SCANCODE_M, "m" });
	sdlKeyCodes->insert({ SDL_SCANCODE_N, "n" });
	sdlKeyCodes->insert({ SDL_SCANCODE_O, "o" });
	sdlKeyCodes->insert({ SDL_SCANCODE_P, "p" });
	sdlKeyCodes->insert({ SDL_SCANCODE_Q, "q" });
	sdlKeyCodes->insert({ SDL_SCANCODE_R, "r" });
	sdlKeyCodes->insert({ SDL_SCANCODE_S, "s" });
	sdlKeyCodes->insert({ SDL_SCANCODE_T, "t" });
	sdlKeyCodes->insert({ SDL_SCANCODE_U, "u" });
	sdlKeyCodes->insert({ SDL_SCANCODE_V, "v" });
	sdlKeyCodes->insert({ SDL_SCANCODE_W, "w" });
	sdlKeyCodes->insert({ SDL_SCANCODE_X, "x" });
	sdlKeyCodes->insert({ SDL_SCANCODE_Y, "y" });
	sdlKeyCodes->insert({ SDL_SCANCODE_Z, "z" });
	sdlKeyCodes->insert({ SDL_SCANCODE_BACKSPACE, "BACKSPACE" });
	sdlKeyCodes->insert({ SDL_SCANCODE_RETURN, "RETURN" });
}
std::string TextBoxInputComponent::getComponentID(){
	return "TextBoxInputComponent";
}