#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

void Game::Init()
{
	// put your initialization code here; will be executed once
}

void Game::Tick(float a_DT)
{
	m_Screen->Clear(0xffff00);
}

void Game::KeyDown(unsigned int code)
{
	printf("Key Down Code: %d \n", code);
}

void Game::MouseMove(unsigned int x, unsigned int y)
{
	printf("Mouse X: %d  Mouse Y: %d \n", x, y);
}

void Game::MouseDown(unsigned int button)
{
	printf("Mouse Down Code: %d \n", button);
}
