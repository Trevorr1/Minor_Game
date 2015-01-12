#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level1::Level1()
{
	/*m_WorldSizeX = 1880;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);*/

	//new level
	m_WorldSizeX = 8312;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height

	//score
	ScoreboardManager::getInstance().resetTimer();
	ScoreboardManager::getInstance().startTimer();
	ScoreboardManager::getInstance().setName("");

	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level1::Level1(GameEntity* player)
{
	m_Player = player;
}

Level1::~Level1()
{
	delete m_Background;
}

void Level1::Init()
{
	//m_Background = new Surface("assets/backgrounds/spooky.png");
	m_Background = new Surface("assets/backgrounds/background_city2.3.png");

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	//m_Camera->setEntityFocus(m_Player);

	//this->addEntities(m_Player);
	//m_Player->setStartingPosition(100, 257); //set to world coordinates
	//m_Camera->setEntityFocus(m_Player);
	//
	//loadXML(1);

	//GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Urquhart);
	//entityCop->setStartingPosition(500, 340);
	////entityCop->addComponent(new EnemyMoveComponent(1184, 1472));
	//this->addEntities(entityCop);
	//
	//SoundManager::getInstance().StopMusic();
	//SoundManager::getInstance().PlayMusic(eMusic::BossFight);
	////SoundManager::getInstance()->PlaySound(eSound::Death);

	//new level
	this->addEntities(m_Player);//(TODO: check if already is in this list??!)
	m_Player->setStartingPosition(100, 410 - 53 - 150); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	//load xml
	loadXML(4); //change this to new level

	/*cop*/
	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(6208, 106);
	entityCop->addComponent(new EnemyMoveComponent(6218, 6390));
	this->addEntities(entityCop);
}
