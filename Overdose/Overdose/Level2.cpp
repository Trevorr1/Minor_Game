#include "stdafx.h"
#include "Level2.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level2::Level2()
{
	m_WorldSizeX = 2560;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level2::Level2(GameEntity* player)
{
	m_Player = player;
}

Level2::~Level2()
{
	delete m_Background;
}

void Level2::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);//(TODO: check if already is in this list??!)
	m_Player->setStartingPosition(100, 257); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	loadXML(2);

	/*GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(500, 356);
	entityCop->addComponent(new EnemyMoveComponent(360, 630));
	this->addEntities(entityCop);*/

	////TODO moet op de surface komen
	//GameEntity* entityTutorial = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_Explanation);
	//entityTutorial->setStartingPosition(210, 100);
	//this->addEntities(entityTutorial);

	/*GameEntity* entityXTC = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_XTC);
	entityXTC->setStartingPosition(600, 200);
	this->addEntities(entityXTC);*/
}
