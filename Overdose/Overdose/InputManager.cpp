#include "InputManager.h"
#include <iostream>
using namespace overdose;

InputManager *InputManager::_instance = nullptr;

InputManager::InputManager()
{
	std::cout << "Succesfully initialised InputManager" << std::endl;
}

InputManager::~InputManager()
{
	delete keyBuffer;
	delete _instance;
}

/* Keyboard Input */
void InputManager::addKeyPress(unsigned int keyPressed) {
	keyBuffer->push(keyPressed);
	std::cout << "Received keypress " << keyPressed << std::endl;
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
	click.x = -1; click.y = -1; click.button = -1;

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
