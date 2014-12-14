#include "stdafx.h"
#include "MainMenu.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

MainMenu::MainMenu()
{
	m_Camera = new Camera();
	m_Background = new Surface("assets/backgrounds/mainmenu.jpg");
}

MainMenu::~MainMenu()
{
	delete m_Background;
	//delete m_Camera; wordt al gedelete in destructor
}

void MainMenu::Init()
{
	/*Test Data*/
	//GameEntity *entityPtr = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	//entityPtr->setSpeedY(0);
	//entityPtr->setPosX(0);
	//this->addEntities(entityPtr);

	GameEntity *buttonPlay = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonPlay);
	buttonPlay->setPosX(50);
	buttonPlay->setPosY(10);
	this->addEntities(buttonPlay);

	GameEntity *buttonLoadGame = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonLoadGame);
	buttonLoadGame->setPosX(50);
	buttonLoadGame->setPosY(85);
	this->addEntities(buttonLoadGame);

	GameEntity *buttonHighscore = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonHighScore);
	buttonHighscore->setPosX(50);
	buttonHighscore->setPosY(160);
	this->addEntities(buttonHighscore);

	GameEntity *buttonOptions = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonOptions);
	buttonOptions->setPosX(50);
	buttonOptions->setPosY(235);
	this->addEntities(buttonOptions);

	GameEntity *buttonCredits = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonCredits);
	buttonCredits->setPosX(50);
	buttonCredits->setPosY(310);
	this->addEntities(buttonCredits);

	GameEntity *buttonQuitGame = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonQuitGameGreen);
	buttonQuitGame->setPosX(50);
	buttonQuitGame->setPosY(385);
	this->addEntities(buttonQuitGame);

	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::MainMenuTheme);
}

bool MainMenu::isGameOver() 
{
	return false;
}
