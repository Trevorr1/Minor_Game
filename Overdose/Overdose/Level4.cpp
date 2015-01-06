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
	m_WorldSizeX = 8312;
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
	m_Background = new Surface("assets/backgrounds/background_city2.3.png");

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);//(TODO: check if already is in this list??!)
	m_Player->setStartingPosition(100, 410 - 53 - 150); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	/*cop*/
	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(6208, 106);
	entityCop->addComponent(new EnemyMoveComponent(6218, 6390));
	this->addEntities(entityCop);

	loadXML(4);

//	SoundManager::getInstance().StopMusic();
//	SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
