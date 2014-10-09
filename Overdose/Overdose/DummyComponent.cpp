#include "DummyComponent.h"
#include <iostream>

using namespace overdose;

void  DummyComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {
	std::cout << "received messages from component: " + message << std::endl;
}

void  DummyComponent::tick(GameEntity *entity) {
	std::cout << "DDummyGameTick" << std::endl;
}
