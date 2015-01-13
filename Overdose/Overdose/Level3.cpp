#include "stdafx.h"
#include "Level3.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level3::Level3()
{
	m_WorldSizeX = 3840;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level3::Level3(GameEntity* player)
{
	m_Player = player;
}

Level3::~Level3()
{
	delete m_Background;
}

void Level3::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);//(TODO: check if already is in this list??!)
	m_Player->setStartingPosition(100, 207); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	loadXML(3);

	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_Policeman);
	entityCop->setStartingPosition(400, 300);
	entityCop->addComponent(new EnemyMoveComponent(300, 600));
	this->addEntities(entityCop);

	GameEntity* entityTutorial = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_Cop);
	entityTutorial->setStartingPosition(600, 10);
	this->addEntities(entityTutorial);

	GameEntity* entityTutorial1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_SpeedDrug);
	entityTutorial1->setStartingPosition(2770, 280);
	this->addEntities(entityTutorial1);

	//SoundManager::getInstance().StopMusic();
	//SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
