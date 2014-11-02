#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

#include "GameEntityFactory.h"
#include "GameEntity.h"
#include "DrawComponent.h"
#include "DrawManager.h"
using namespace overdose;



Game::Game(){
	
}
Game::~Game(){
//	delete m_Screen;
}

void Game::Init()
{
	// put your initialization code here; will be executed once
	DrawManager::getInstance().setTargetSurface(m_Screen);
}

void Game::Tick(float a_DT)
{
	LevelManager::getInstance().Tick(a_DT);
	InputManager::getInstance().clearKeyBuffer();
	InputManager::getInstance().clearMouseBuffer();
}

void Game::KeyStates(const Uint8 *keyStates) {
	InputManager::getInstance().setKeyStates(keyStates);
}




void Game::MouseMove(unsigned int x, unsigned int y)
{
	m_mouseX = x;
	m_mouseY = y;
}

void Game::MouseDown(unsigned int button)
{
	MouseClick click;
	click.x = m_mouseX;
	click.y = m_mouseY;
	click.button = button;
	InputManager::getInstance().addMouseClick(click);
}

