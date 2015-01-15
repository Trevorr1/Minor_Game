#include "stdafx.h"
#include "Level7.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level7::Level7()
{
	m_WorldSizeX = 3840;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level7::Level7(GameEntity* player)
{
	m_Player = player;
}

Level7::~Level7()
{
	delete m_Background;
}

void Level7::Init()
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

	loadXML(7);

	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(450, 363);
	entityCop->addComponent(new EnemyMoveComponent(408, 710));
	this->addEntities(entityCop);

	GameEntity* entityCop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop2->setStartingPosition(2450, 139);
	entityCop2->addComponent(new EnemyMoveComponent(2400, 2500));
	this->addEntities(entityCop2);

	GameEntity* entityCop3 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop3->setStartingPosition(2950, 395);
	entityCop3->addComponent(new EnemyMoveComponent(2860, 3000));
	this->addEntities(entityCop3);


	//SoundManager::getInstance().StopMusic();
	//SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
