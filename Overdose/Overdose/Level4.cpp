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
	//m_WorldSizeX = 8312;
	//m_WorldSizeY = 480;
	//m_Camera = new Camera(m_WorldSizeX);
	//createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
	
	//boss fight
	m_WorldSizeX = 1880;
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
	//m_Background = new Surface("assets/backgrounds/background_city2.3.png");
	m_Background = new Surface("assets/backgrounds/spooky.png");

	if (m_Player == nullptr)
	{
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}


	//boss fight
	m_Camera->setEntityFocus(m_Player);

	this->addEntities(m_Player);
	m_Player->setStartingPosition(100, 257); //set to world coordinates
	m_Camera->setEntityFocus(m_Player);

	loadXML(4); //change this to new level

	m_Urquhart = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Urquhart);
	m_Urquhart->setStartingPosition(500, 340);

	this->addEntities(m_Urquhart);

	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::BossFight);

}

bool Level4::isGameWon() {
	// Let the player enjoy FU's blood for a second before marking the boss as defeated.
	if (m_UrquhartTimeOfDeath == -1 && m_Urquhart->isScheduledForRemoval()) {
		m_UrquhartTimeOfDeath = time(0);
	}
	

	return m_UrquhartTimeOfDeath != -1 && std::difftime(time(0), m_UrquhartTimeOfDeath) >= 1;
}