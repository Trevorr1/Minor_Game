#include "stdafx.h"
#include "Factory.h"
#include "InputManager.h"

using namespace overdose;

int main(int argc, const char* argv[])
{

	//moet ff uitzoeken hoe de componentContainer benaderbaar is via GameEntitty
	GameEntity *entity = Factory::getInstance()->getGameEntity(eGameEntity::Policeman);

	InputManager *input = new InputManager;
	
	// hier later nog een keer een gameloop met dt enzo
	while (true) {

		input->addKeyPress("Keypad 1");
		input->addKeyPress("C");

		entity->tick();

		//std::cout << "PosX " << entity->getPosX() << "PosY " << entity->getPosY() << std::endl;
		//std::cout << "Last key press: " << input->getLastKeyPress() << std::endl;
		system("pause");
	}

	delete entity;
	delete input;

	return 0;
}
