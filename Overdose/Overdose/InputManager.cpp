#include "InputManager.h"
#include <iostream>
using namespace overdose;

InputManager *InputManager::_instance = nullptr;

InputManager::InputManager()
{

}

InputManager::~InputManager()
{
	delete keyBuffer;
	delete _instance;
}

/* Keyboard Input */
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
	while (!keyBuffer->empty()) {
		keyBuffer->pop();
	}
}

/* Mouse Input */
void InputManager::addMouseClick(MouseClick click) {
	mouseBuffer->push(click);
}

MouseClick InputManager::getLastMouseClick() {
	MouseClick click;

	if (!mouseBuffer->empty()) {
		click = mouseBuffer->top();
		clearMouseBufferButOne();
	}

	return click;
}

void InputManager::clearMouseBuffer() {
	while (!mouseBuffer->empty()) {
		mouseBuffer->pop();
	}
}

void InputManager::clearMouseBufferButOne() {
	while (mouseBuffer->size() > 1)  {
		mouseBuffer->pop();
	}
}

InputManager* InputManager::getInstance() {
	if (InputManager::_instance == nullptr) {
		InputManager::_instance = new InputManager;
	}
	return InputManager::_instance;
}
