#include "stdafx.h"
#include "Level8.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level8::Level8()
{
	m_WorldSizeX = 2560;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level8::Level8(GameEntity* player)
{
	m_Player = player;
}

Level8::~Level8()
{
	delete m_Background;
}

void Level8::Init()
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
	cop1->setStartingPosition(760, 363);
	cop1->addComponent(new EnemyMoveComponent(754, 968));

	GameEntity *cop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop2->setStartingPosition(1250, 363);
	cop2->addComponent(new EnemyMoveComponent(1200, 1327));

	GameEntity *cop3 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop3->setStartingPosition(1400, 363);
	cop3->addComponent(new EnemyMoveComponent(1395, 1580));

	GameEntity *cop4 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop4->setStartingPosition(1565, 75);
	cop4->addComponent(new EnemyMoveComponent(1510, 1620));

	GameEntity *cop5 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop5->setStartingPosition(460, 75);
	cop5->addComponent(new EnemyMoveComponent(300, 620));

	addEntities(cop1);
	addEntities(cop2);
	addEntities(cop3);
	addEntities(cop4);
	addEntities(cop5);
	loadXML(8);

}