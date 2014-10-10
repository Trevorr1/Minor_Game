#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

#include "Factory.h"
#include "GameEntity.h"
#include "DrawComponent.h"
#include "DrawManager.h"

using namespace overdose;

Game::~Game()
{
	delete m_LevelManager;
}

void Game::Init()
{
	// put your initialization code here; will be executed once
	m_LevelManager = LevelManager::getInstance();
	DrawManager::getInstance()->setTargetSurface(m_Screen);
}

void Game::Tick(float a_DT)
{
	m_LevelManager->Tick(a_DT);
	InputManager::getInstance()->clearKeyBuffer();
}


void Game::KeyDown(unsigned int code)
{
	InputManager::getInstance()->addKeyPress(code);
	printf("Key Down Code: %d \n", code);
}

void Game::MouseMove(unsigned int x, unsigned int y)
{
	//printf("Mouse X: %d  Mouse Y: %d \n", x, y);
}

void Game::MouseDown(unsigned int button)
{
	//printf("Mouse Down Code: %d \n", button);
}

