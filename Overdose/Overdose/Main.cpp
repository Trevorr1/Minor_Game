#include "stdafx.h"
#include <iostream>


using namespace overdose;


int main(int argc, const char* argv[])
{

	//moet ff uitzoeken hoe de componentContainer benaderbaar is via GameEntitty
	GameEntity *entity = new GameEntity;
	entity->addComponent(*new DummyComponent);
	entity->addComponent(*new MoveComponent);

	// hier later nog een keer een gameloop met dt enzo
	while (true) {

		
		entity->tick();

		std::cout << "PosX " << entity->getPosX() << "PosY " << entity->getPosY() << std::endl;
		system("pause");
	}

	return 0;
}