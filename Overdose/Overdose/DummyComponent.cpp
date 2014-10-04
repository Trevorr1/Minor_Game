#include "DummyComponent.h"
#include <iostream>

using namespace overdose;

void  DummyComponent::receive(Component &component, int message) {
	std::cout << "received messages from component: " + message << std::endl;
}

void  DummyComponent::tick(GameEntity &entity, Level &level) {
	std::cout << "GameTick" << std::endl;
}
