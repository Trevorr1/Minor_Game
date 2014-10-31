#include "stdafx.h"
#include "GameWon.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;


GameWon::GameWon()
{
	m_Background = new Surface("assets/backgrounds/Party-Time2.png");
}


GameWon::~GameWon()
{
	delete m_Background;

}

void GameWon::Init(){

	/*BUTTONS*/
	GameEntity *entityPtr = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	GameEntity *buttonPlayAgain = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonPlayAgain);
	buttonPlayAgain->setPosX(340);
	buttonPlayAgain->setPosY(200);
	this->addEntities(buttonPlayAgain);

	GameEntity *buttonMainMenu = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonMainMenu);
	buttonMainMenu->setPosX(340);
	buttonMainMenu->setPosY(300);
	this->addEntities(buttonMainMenu);


	/* MUSIC/SOUND */
	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(People); 
	SoundManager::getInstance().PlaySound(PartyHorn);
}

bool GameWon::isGameOver() {
	return false;
}