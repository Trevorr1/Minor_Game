#include "InputManager.h"

using namespace overdose;


InputManager::InputManager()
{
	std::cout << "Succesfully initialised InputManager" << std::endl;
}

InputManager::~InputManager()
{
	//delete m_keystates;
	delete m_mouseBuffer;
	delete m_keystateBuffer;
}

void InputManager::setKeyStates(Uint8 *keyStates, int size) {

	m_keystateBuffer->push_back(m_keystate);
	m_keystate = new Uint8[size]; // memleak?
	for (int i = 0; i < size; i++) {
		m_keystate[i] = keyStates[i];
	}
		//m_keystate = keyStates;
	if (m_keystateBuffer->size() > KEYBOARD_BUFFER_SIZE) {
	//	delete m_keystateBuffer->front();
		m_keystateBuffer->pop_front();
	}


}

/* Keyboard Input */


bool InputManager::isKeyPressed(int sdl_code) {
	if (m_keystate == nullptr) {
		return false;
	}
	return m_keystate[sdl_code];
//	return true;
}
// Niet echt een keyreleased oid, maar lijkt wel te werken. ^^
bool InputManager::isKeyPressedOnce(int sdl_code) {
	if (m_keystateBuffer->size() < KEYBOARD_BUFFER_SIZE) {
		return false;
	}
	
	bool isKeyPressed = true;
	list<Uint8*>::const_iterator iterator = m_keystateBuffer->begin();
	int counter = 0;

	while (iterator != m_keystateBuffer->end() && isKeyPressed && counter < KEYBOARD_BUFFER_SIZE / 2) {

		Uint8 *keystate = *iterator;
		isKeyPressed = keystate[sdl_code];
	
		iterator++;
		counter++;
	}


	bool isKeyReleased = true;
	while (iterator != m_keystateBuffer->end() && isKeyReleased) {

		Uint8 *keystate = *iterator;

		isKeyReleased = (keystate[sdl_code] == false);
		iterator++;
		
	}

	
	return isKeyPressed && isKeyReleased;
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
