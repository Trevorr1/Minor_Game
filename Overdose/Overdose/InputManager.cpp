#include "InputManager.h"

using namespace overdose;

InputManager::InputManager()
{

}

void InputManager::addKeyPress(int keyPressed) {
	keyBuffer->push(keyPressed);
}

int InputManager::getLastKeyPress() {
	int keyPress = -1;

	if (!keyBuffer->empty()) {
		keyPress = keyBuffer->top();
		clearKeyBufferButOne();
	}

	return keyPress;
}

void InputManager::clearKeyBufferButOne() {
	while (keyBuffer->size() > 1)  {
		keyBuffer->pop();
	}
}

InputManager::~InputManager()
{
	delete keyBuffer;
}
