#include "stdafx.h"
#include "LevelBoss.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"
#include "DrawManager.h"
#include "ScoreboardManager.h"

using namespace overdose;

LevelBoss::LevelBoss()
{	
	//boss fight
	m_WorldSizeX = 1920;
	m_WorldSizeY = 480;
	m_Camera = new Camera(m_WorldSizeX);

	createLevel(m_WorldSizeX, m_WorldSizeY); //create the level here widthx height
}

LevelBoss::LevelBoss(GameEntity* player)
{
	m_Player = player;
}

LevelBoss::~LevelBoss()
{
	delete m_Background;
}

void LevelBoss::Init()
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

	// lets make sure it does not conflict BossFight is the last level :3
	loadXML(100); //change this to new level

	m_Urquhart = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Urquhart);
	m_Urquhart->setStartingPosition(1280, 340);

	this->addEntities(m_Urquhart);

	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::BossFight);

}

bool LevelBoss::isGameWon() {
	// Let the player enjoy FU's blood for a second before marking the boss as defeated.
	if (m_UrquhartTimeOfDeath == -1 && m_Urquhart->isScheduledForRemoval()) {
		m_UrquhartTimeOfDeath = time(0);
		/* SOUND/MUSIC */
		SoundManager::getInstance().StopMusic();
		SoundManager::getInstance().PlaySound(eSound::GameOverSound);
	}
	


	return m_UrquhartTimeOfDeath != -1 && std::difftime(time(0), m_UrquhartTimeOfDeath) >= 4.5;
}