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

GameEntity* entityPtr = nullptr;
GameEntity& entInvader = *new GameEntity();
DrawComponent* drawInvader = nullptr;

void Game::Init()
{
	// put your initialization code here; will be executed once
	entityPtr = Factory::getInstance()->getGameEntity(eGameEntity::DrugAddict);
	drawInvader = new DrawComponent("assets/bottom_enemy_anim.tga", 3);
	entityPtr->addComponent(*drawInvader);
	DrawManager::getInstance()->setTargetSurface(m_Screen);
}

void Game::Tick(float a_DT)
{
	m_Screen->Clear(0x000000);

	entityPtr->tick();
	//drawInvader->tick(entInvader);
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
