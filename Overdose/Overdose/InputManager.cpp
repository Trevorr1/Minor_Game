#include "stdafx.h"

using namespace overdose;

InputManager::InputManager()
{

}

void InputManager::addKeyPress(string keyPressed) {
	keyBuffer->push(keyPressed);
}

string InputManager::getLastKeyPress() {
	string keyPress = "";

	if (!keyBuffer->empty()) {
		keyPress = keyBuffer->top();
		clearKeyBuffer();
	}

	return keyPress;
}

void InputManager::clearKeyBuffer() {
	while (!keyBuffer->empty()) {
		keyBuffer->pop();
	}
}

InputManager::~InputManager()
{
	delete keyBuffer;
}
