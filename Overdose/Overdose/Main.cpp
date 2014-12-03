#include "stdafx.h"
#include "GameEntityFactory.h"
#include "InputManager.h"

#include "game.h"
#include "SDLTemplate.h"
#include <vld.h>
using namespace overdose;

void teardown() {
	
}

int main(int argc, const char* argv[])
{
	
	atexit(teardown);
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	/******************
	 Ricardo's template
	 *******************/
	{
		SDLTemplate sdltemplate;
		sdltemplate.initTemplate(); //This method contains a game loop. Change to embedded loops?
	}
	//_CrtDumpMemoryLeaks();

	
	return 0;
}


