#include "FPSDrawComponent.h"

using namespace overdose;

void FPSDrawComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void FPSDrawComponent::tick(float dt, GameEntity *entity) {
	
	calculateTicksOnScreen();

	if (ticksOnScreen > 0) {
		Surface *surface = DrawManager::getInstance()->getSurface();

		// Hoe bereken je nou de FPS? :P
		int fps = (dt / 1000 * 1000);

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
		ticksOnScreen = 10000;
	}
}