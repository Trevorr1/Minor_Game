#include "FPSDrawComponent.h"

using namespace overdose;

void FPSDrawComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
}

void FPSDrawComponent::receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages) {}

/* DT: last frametime in milliseconds */
void FPSDrawComponent::tick(float dt, GameEntity *entity) {
	
	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_GRAVE)) { // tilde 
		if (drawTimer <= 0){
			draw = (draw) ? false : true;
			drawTimer = 30;
		}
	}
	
	if (draw) {
		Surface *surface = DrawManager::getInstance().getSurface();

		m_ticks++;
		m_dt = m_dt + dt;
		
		if (m_dt > 1) {
			m_fps = m_ticks;
			std::cout << "FPS " << m_fps << std::endl;
			m_ticks = 0;
			m_dt = m_dt - 1;
		}

		// En dit casten kan waarschijnlijk beter
		std::string str = std::to_string(m_fps);
		const char *t = str.c_str();
		char *fps_chars = const_cast<char*>(t);

		surface->Print(fps_chars, (int)entity->getPosX(), (int)entity->getPosY(), *new Pixel(0xff0000));
	}

	if (drawTimer > 0){
		drawTimer--;
	}

}

std::string FPSDrawComponent::getComponentID(){
	return "FPSDrawComponent";
}