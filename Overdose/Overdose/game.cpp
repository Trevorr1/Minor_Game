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

	if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_M)){
		SoundManager::getInstance().ToggleMute();
	}
}

void Game::KeyStates(Uint8 *keyStates, int size) {
	InputManager::getInstance().setKeyStates(keyStates, size);
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

