#include "MouseBaseComponent.h"

using namespace overdose;

bool MouseBaseComponent::isMouseHover(GameEntity* entity, int x, int y) {
	return (x >= entity->getPosX() && x <= entity->getPosX() + entity->getWidth() &&
			y >= entity->getPosY() && y <= entity->getPosY() + entity->getHeight());
}
