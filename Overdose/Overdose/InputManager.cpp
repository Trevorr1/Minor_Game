#include "InputManager.h"

using namespace overdose;


InputManager::InputManager()
{
	std::cout << "Succesfully initialised InputManager" << std::endl;
}

InputManager::~InputManager()
{
	//delete m_keystates;

}

void InputManager::setKeyStates(const Uint8 *keyStates) {
	m_keystates = keyStates;
}

/* Keyboard Input */


bool InputManager::isKeyPressed(int sdl_code) {

	if (m_keystates == nullptr) {
		return false;
	}
	return m_keystates[sdl_code];
//	return true;
}

void InputManager::clearKeyBuffer() {
//	delete m_keystates;
}



/* Mouse Input */
void InputManager::addMouseClick(MouseClick click) {
	m_mouseBuffer->push(click);
}

MouseClick InputManager::getLastMouseClick() {
	MouseClick click;
	click.x = -1; click.y = -1; click.button = -1;

	if (!m_mouseBuffer->empty()) {
		click = m_mouseBuffer->top();
		clearMouseBufferButOne();
	}

	return click;
}

void InputManager::clearMouseBuffer() {
	while (!m_mouseBuffer->empty()) {
		m_mouseBuffer->pop();
	}
}

void InputManager::clearMouseBufferButOne() {
	while (m_mouseBuffer->size() > 1)  {
		m_mouseBuffer->pop();
	}
}

InputManager &InputManager::getInstance() {
	static InputManager _instance;
	return _instance;
}
