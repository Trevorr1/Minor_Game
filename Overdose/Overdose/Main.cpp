
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
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/******************
	 Ricardo's template
	*******************/
	sdltemplate = new SDLTemplate();
	sdltemplate->initTemplate(); //This method contains a game loop. Change to embedded loops?

	
	return 0;
}
