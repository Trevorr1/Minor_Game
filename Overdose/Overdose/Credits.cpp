#include "stdafx.h"
#include "Credits.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Credits::Credits()
{
	m_Camera = new Camera();
	m_Background = new Surface("assets/backgrounds/credits.jpg");
}

Credits::~Credits()
{
	delete m_Background;
}

void Credits::Init()
{

	GameEntity *buttonPlay = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonPlay);
	buttonPlay->setPosX(50);
	buttonPlay->setPosY(100);
	this->addEntities(buttonPlay);

	GameEntity *buttonMainMenu = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonMainMenu);
	buttonMainMenu->setPosX(50);
	buttonMainMenu->setPosY(200);
	this->addEntities(buttonMainMenu);

	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::MainMenuTheme);
}