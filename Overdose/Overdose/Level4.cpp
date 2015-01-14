#include "stdafx.h"
#include "Level4.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level4::Level4()
{
	m_WorldSizeX = 3840;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level4::Level4(GameEntity* player)
{
	m_Player = player;
}

Level4::~Level4()
{
	delete m_Background;
}

void Level4::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);//(TODO: check if already is in this list??!)
	m_Player->setStartingPosition(100, 50); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	GameEntity *cop1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop1->setStartingPosition(100, 350);
	cop1->addComponent(new EnemyMoveComponent(75, 220));

	GameEntity *cop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop2->setStartingPosition(1100, 299);
	cop2->addComponent(new EnemyMoveComponent(1033, 1343));

	GameEntity *cop3 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop3->setStartingPosition(2500, 203);
	cop3->addComponent(new EnemyMoveComponent(2400, 2543));

	GameEntity *cop4 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop4->setStartingPosition(1300, 139);
	cop4->addComponent(new EnemyMoveComponent(1255, 1341));

	addEntities(cop1);
	addEntities(cop2);
	addEntities(cop3);
	addEntities(cop4);
	loadXML(4);

}
