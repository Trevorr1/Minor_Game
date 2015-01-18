#include "stdafx.h"
#include "Level9.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

Level9::Level9()
{
	m_WorldSizeX = 2560;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);
	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

Level9::Level9(GameEntity* player)
{
	m_Player = player;
}

Level9::~Level9()
{
	delete m_Background;
}

void Level9::Init()
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
	cop1->setStartingPosition(1246, 235);
	cop1->addComponent(new EnemyMoveComponent(1195, 1246));

	GameEntity *cop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop2->setStartingPosition(1432, 139);
	cop2->addComponent(new EnemyMoveComponent(1387, 1476));

	GameEntity *cop3 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop3->setStartingPosition(1563,75);
	cop3->addComponent(new EnemyMoveComponent(1535,1610));

	GameEntity *cop4 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop4->setStartingPosition(1727,139);
	cop4->addComponent(new EnemyMoveComponent(1700, 1756));

	GameEntity *cop5 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	cop5->setStartingPosition(1795, 139);
	cop5->addComponent(new EnemyMoveComponent(1770, 1834));

	addEntities(cop1);
	addEntities(cop2);
	addEntities(cop3);
	addEntities(cop4);
	addEntities(cop5);
	loadXML(9);

}

bool Level9::isGameWon() {
	if (ILevel::isGameWon() && m_sirenStart == -1) {

		m_sirenStart = time(0);
		SoundManager::getInstance().StopMusic();
		SoundManager::getInstance().PlaySound(Siren);
	}

	return m_sirenStart != -1 && std::difftime(time(0), m_sirenStart) >= 3;

}