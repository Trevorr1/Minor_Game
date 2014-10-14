#include "FPSDrawComponent.h"

using namespace overdose;

void FPSDrawComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

/* DT: last frametime in milliseconds */
void FPSDrawComponent::tick(float dt, GameEntity *entity) {
	
	calculateTicksOnScreen();


	
	if (ticksOnScreen > 0) {
		Surface *surface = DrawManager::getInstance()->getSurface();

		m_ticks++;
		m_dt = m_dt + dt;

		int fps = 0;

		
		fps = m_ticks / (m_dt / 1000);

		if (m_dt / 1000 > 1) {
			std::cout << "FPS " << fps << std::endl;
			m_ticks = 0;
			m_dt = 0;
		}
		


		// En dit casten kan waarschijnlijk beter
		std::string str = std::to_string(fps);
		const char *t = str.c_str();
		char *fps_chars = const_cast<char*>(t);

		surface->Print(fps_chars, entity->getPosX(), entity->getPosY(), *new Pixel(0xff0000));
		--ticksOnScreen;
	}

}

void FPSDrawComponent::calculateTicksOnScreen() {

	int keyDown = InputManager::getInstance()->getLastKeyPress();

	if (keyDown == 53) { // tilde 
		ticksOnScreen = 180;
	}
}