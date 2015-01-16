#include "stdafx.h"
#include "Level6.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level6::Level6()
{
	m_WorldSizeX = 3840;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level6::Level6(GameEntity* player)
{
	m_Player = player;
}

Level6::~Level6()
{
	delete m_Background;
}

void Level6::Init()
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

	loadXML(6);

	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(270, 365);
	entityCop->addComponent(new EnemyMoveComponent(258, 350));
	this->addEntities(entityCop);

	GameEntity* entityCop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop2->setStartingPosition(2420, 107);
	entityCop2->addComponent(new EnemyMoveComponent(2402, 2510));
	this->addEntities(entityCop2);

	GameEntity* entityCop3 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop3->setStartingPosition(1085, 365);
	entityCop3->addComponent(new EnemyMoveComponent(995, 1140));
	this->addEntities(entityCop3);


	//SoundManager::getInstance().StopMusic();
	//SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
