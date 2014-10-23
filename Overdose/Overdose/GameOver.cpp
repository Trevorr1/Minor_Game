#include "stdafx.h"
#include "GameOver.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;



GameOver::GameOver()
{
	entities = new std::vector<GameEntity*>();
	enemies = new std::vector<GameEntity*>();
	collectibles = new std::vector<GameEntity*>();
	m_Background = new Surface("assets/backgrounds/gameover.jpg");
}


GameOver::~GameOver()
{
	delete entities;
	delete collectibles;
	delete m_Background;
	delete enemies;
}

void GameOver::Init()
{

	/*BUTTONS*/
	GameEntity *entityPtr = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	GameEntity *buttonPlayAgain = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonPlayAgain);
	buttonPlayAgain->setPosX(100);
	buttonPlayAgain->setPosY(150);
	this->addEntities(buttonPlayAgain);

	GameEntity *buttonMainMenu = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonMainMenu);
	buttonMainMenu->setPosX(100);
	buttonMainMenu->setPosY(250);
	this->addEntities(buttonMainMenu);


	/* SOUND/MUSIC */
	SoundManager::getInstance()->StopMusic();
	SoundManager::getInstance()->PlaySound(eSound::GameOverSound);
	SoundManager::getInstance()->PlaySound(eSound::Death);
}

bool GameOver::isGameOver() {
	return false;
}