#include "stdafx.h"
#include "GameWon.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "ScoreboardManager.h"
#include "TextGameEntity.h"

using namespace overdose;


GameWon::GameWon()
{
	m_Camera = new Camera();
	m_Background = new Surface("assets/backgrounds/Party-Time2.png");
	ScoreboardManager::getInstance().stopTimer();
}


GameWon::~GameWon()
{
	delete m_Background;

}

void GameWon::Init(){

	/*BUTTONS*/
	GameEntity *entityPtr = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	std::string to_char = "you beat the game in " + std::to_string(int(ScoreboardManager::getInstance().getScore())) + " seconds enter your name and press enter";
	char* score = _strdup(to_char.c_str());

	TextGameEntity* text = new TextGameEntity(score);

	text->setPosX(200);
	text->setPosY(125);
	text->setHeight(15);
	this->addEntities(text);

	GameEntity *highscore = GameEntityFactory::getInstance().getGameEntity(eGameEntity::TextBox);
	highscore->setPosY(175);
	highscore->setPosX(350);
	this->addEntities(highscore);

	GameEntity *buttonPlayAgain = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonPlayAgain);
	buttonPlayAgain->setPosX(340);
	buttonPlayAgain->setPosY(250);
	this->addEntities(buttonPlayAgain);

	GameEntity *buttonMainMenu = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonMainMenu);
	buttonMainMenu->setPosX(340);
	buttonMainMenu->setPosY(350);
	this->addEntities(buttonMainMenu);


	/* MUSIC/SOUND */
	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(People); 
	SoundManager::getInstance().PlaySound(PartyHorn);

}

bool GameWon::isGameOver() {
	return false;
}