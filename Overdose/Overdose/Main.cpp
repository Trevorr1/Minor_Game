
#define CRTDBG_MAP_ALLOC
#include "stdafx.h"
#include "GameEntityFactory.h"
#include "InputManager.h"

#include "game.h"
#include "SDLTemplate.h"


using namespace overdose;


SDLTemplate* sdltemplate = nullptr;


int main(int argc, const char* argv[])
{

	//moet ff uitzoeken hoe de componentContainer benaderbaar is via GameEntitty
	GameEntity *entity = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Policeman);

	

	/******************
	 Ricardo's template
	*******************/
	sdltemplate = new SDLTemplate();
	sdltemplate->initTemplate(); //This method contains a game loop. Change to embedded loops?


	// hier later nog een keer een gameloop met dt enzo
	/*while (true) {

		input->addKeyPress(456);
		input->addKeyPress(45);
		
		entity->tick();

		//std::cout << "PosX " << entity->getPosX() << "PosY " << entity->getPosY() << std::endl;
	    //std::cout << "Last key press: " << input->getLastKeyPress() << std::endl;
		system("pause");
	}*/

	

	delete entity;


	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	return 0;
}
