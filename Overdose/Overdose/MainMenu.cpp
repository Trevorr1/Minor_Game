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
	m_Background = new Surface("assets/backgrounds/mainmenu.jpg");
}


MainMenu::~MainMenu()
{
	delete m_Background;

}

void MainMenu::Init()
{
	/*Test Data*/
	GameEntity *entityPtr = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	GameEntity *buttonPlay = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonPlay);
	buttonPlay->setPosX(50);
	buttonPlay->setPosY(100);
	this->addEntities(buttonPlay);

	GameEntity *buttonQuitGame = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonQuitGameGreen);
	buttonQuitGame->setPosX(50);
	buttonQuitGame->setPosY(200);
	this->addEntities(buttonQuitGame);

	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::MainMenuTheme);


}

bool MainMenu::isGameOver() {
	return false;
}
