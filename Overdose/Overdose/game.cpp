#include "string.h"
#include "surface.h"
#include "stdlib.h"
#include "template.h"
#include "game.h"

#include "GameEntityFactory.h"
#include "GameEntity.h"
#include "DrawComponent.h"
#include "DrawManager.h"
#include "SoundManager.h"
using namespace overdose;



Game::Game(){
	m_LevelManager = LevelManager::getInstance();
}
Game::~Game(){
	delete m_LevelManager;
}

void Game::Init()
{
	// put your initialization code here; will be executed once
	DrawManager::getInstance()->setTargetSurface(m_Screen);
	SoundManager::getInstance()->PlayMusic(MainMenu);
}

void Game::Tick(float a_DT)
{
	m_LevelManager->Tick(a_DT);
	InputManager::getInstance()->clearKeyBuffer();
	InputManager::getInstance()->clearMouseBuffer();
}


void Game::KeyDown(unsigned int code)
{
	InputManager::getInstance()->addKeyPress(code);
	printf("Key Down Code: %d \n", code);
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
	InputManager::getInstance()->addMouseClick(click);
}

