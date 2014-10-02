#include "stdafx.h"
#include <iostream>

#include "game.h"
#include "SDLTemplate.h"


using namespace overdose;


SDLTemplate* sdltemplate = nullptr;


int main(int argc, const char* argv[])
{

	//moet ff uitzoeken hoe de componentContainer benaderbaar is via GameEntitty
	GameEntity *entity = new GameEntity;
	entity->addComponent(*new DummyComponent);
	entity->addComponent(*new MoveComponent);

	/******************
	 Ricardo's template
	*******************/
	sdltemplate = new SDLTemplate();
	sdltemplate->initTemplate(); //This method contains a game loop. Change to embedded loops?


	// hier later nog een keer een gameloop met dt enzo
	/*while (true) {

		
		entity->tick();

		std::cout << "PosX " << entity->getPosX() << "PosY " << entity->getPosY() << std::endl;
		system("pause");
	}*/

	

	return 0;
}
