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
	//DrawManager::getInstance().setTargetSurface(m_Screen);
	DrawManager::getInstance().setTargetCameraSurface(m_Screen);
}

void Game::Tick(float a_DT)
{
	LevelManager::getInstance().Tick(a_DT);
	InputManager::getInstance().clearKeyBuffer();
	InputManager::getInstance().clearMouseBuffer();

	//Todo: This should imo be put on one key and just use the 'ToggleMute()' function (without a parameter), but for that we need a 'isKeyReleased()' method in the inputManager
	// Also.. this code might need to be repositioned to somewhere else, maybe the levelManager, i don't know...
	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_M)){
		SoundManager::getInstance().ToggleMute(true);
	}
	if (InputManager::getInstance().isKeyPressed(SDL_SCANCODE_N)){
		SoundManager::getInstance().ToggleMute(false);
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

