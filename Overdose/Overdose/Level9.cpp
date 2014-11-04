#include "stdafx.h"
#include "Level9.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level9::Level9()
{
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

	if (m_Player == nullptr){
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);
	m_Player->setStartingPosition(50, 114);


	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		if (i % 2 == 0) {
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * i, 452 - 16 * i);
			this->addEntities(grass1);
		}
	}


	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 30);
	this->addEntities(flaggot);

}