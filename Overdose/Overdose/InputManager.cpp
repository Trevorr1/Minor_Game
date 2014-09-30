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
