#include "stdafx.h"
#include <iostream>


using namespace overdose;


int main(int argc, const char* argv[])
{

	//moet ff uitzoeken hoe de componentContainer benaderbaar is via GameEntitty
	GameEntity *entity = new GameEntity;



	entity->addComponent(*new DummyComponent);
	entity->addComponent(*new DummyComponent);
	entity->tick();

	
	system("pause");

	return 0;
}
