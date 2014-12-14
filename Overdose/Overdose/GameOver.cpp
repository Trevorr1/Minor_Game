#include "stdafx.h"
#include "GameOver.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "ScoreboardManager.h"

using namespace overdose;



GameOver::GameOver()
{
	m_Camera = new Camera();
	m_Background = new Surface("assets/backgrounds/gameover.jpg");
	ScoreboardManager::getInstance().stopTimer();
}


GameOver::~GameOver()
{
	delete m_Background;
}

void GameOver::Init()
{

	/*BUTTONS*/
	GameEntity *entityPtr = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	GameEntity *buttonPlayAgain = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonPlayAgainGreen);
	buttonPlayAgain->setPosX(50);
	buttonPlayAgain->setPosY(150);
	this->addEntities(buttonPlayAgain);

	GameEntity *buttonMainMenu = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonMainMenuGreen);
	buttonMainMenu->setPosX(50);
	buttonMainMenu->setPosY(250);
	this->addEntities(buttonMainMenu);


	/* SOUND/MUSIC */
	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlaySound(eSound::GameOverSound);
	SoundManager::getInstance().PlaySound(eSound::Death);
}

bool GameOver::isGameOver() {
	return false;
}