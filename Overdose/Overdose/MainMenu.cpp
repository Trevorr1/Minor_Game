#include "stdafx.h"
#include "MainMenu.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;


/*Test Data*/
//GameEntity* entityPtr = nullptr;

MainMenu::MainMenu()
{
	entities = new std::vector<GameEntity*>();
	enemies = new std::vector<GameEntity*>();
	collectibles = new std::vector<GameEntity*>();
	m_Background = new Surface("assets/backgrounds/mainmenu.jpg");
}


MainMenu::~MainMenu()
{
	delete entities;
	delete collectibles;
	delete m_Background;
	delete enemies;
}

void MainMenu::Init()
{
	/*Test Data*/
	GameEntity *entityPtr = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	entityPtr->setSpeedY(0);
	entityPtr->setPosX(0);
	this->addEntities(entityPtr);

	GameEntity *button = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::ButtonPlay);
	button->setPosX(100);
	button->setPosY(100);
	this->addEntities(button);

	SoundManager::getInstance()->PlayMusic(eMusic::MainMenuTheme);


}
