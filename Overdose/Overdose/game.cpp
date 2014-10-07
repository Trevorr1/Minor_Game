#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

using namespace overdose;

void Game::Init()
{
	// put your initialization code here; will be executed once

}

void Game::Tick(float a_DT)
{
	overdose::InputManager::getInstance()->clearKeyBuffer();
	m_LevelManager->Tick(a_DT);
}

void Game::Render(){
	m_Screen->Clear(0xffff00);
	m_LevelManager->Render(m_Screen);
}

void Game::KeyDown(unsigned int code)
{
	overdose::InputManager::getInstance()->addKeyPress(code);
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

Game::Game(){
	m_LevelManager = new LevelManager();
}
Game::~Game(){
	delete m_LevelManager;
}