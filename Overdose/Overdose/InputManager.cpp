#include "InputManager.h"
#include <iostream>
using namespace overdose;

InputManager *InputManager::_instance = nullptr;

InputManager::InputManager()
{

}

void InputManager::addKeyPress(unsigned int keyPressed) {
	keyBuffer->push(keyPressed);
}

int InputManager::getLastKeyPress() {
	int keyPress = -1;

	if (!keyBuffer->empty()) {
		keyPress = keyBuffer->top();
		clearKeyBufferButOne();
	}
	if (keyPress != -1)
		std::cout << "Retrieving keycode " << keyPress << std::endl;
	return keyPress;
}

void InputManager::clearKeyBufferButOne() {
	while (keyBuffer->size() > 1)  {
		keyBuffer->pop();
	}
}

void InputManager::clearKeyBuffer() {
	std::cout << "Emptying keybuffer" << std::endl;
	while (!keyBuffer->empty()) {
		keyBuffer->pop();
	}
}


InputManager::~InputManager()
{
	delete keyBuffer;
	delete _instance;
}

InputManager* InputManager::getInstance() {
	if (InputManager::_instance == nullptr) {
		InputManager::_instance = new InputManager;
	}
	return InputManager::_instance;
}
