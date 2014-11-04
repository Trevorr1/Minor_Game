#include "stdafx.h"
#include "Level10.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level10::Level10()
{
}

Level10::Level10(GameEntity* player)
{
	m_Player = player;
}

Level10::~Level10()
{
	delete m_Background;
}

void Level10::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr){
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);
	m_Player->setStartingPosition(50, 200);

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(50, 378 - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);


	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		if (i % 4 != 0) continue;
		int posY;
		if (i % 2 == 0) {
			posY = 378;
		}

		else {
			posY = 420;

		}
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 42 * i, posY);
		this->addEntities(grass1);
	}
		GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
		flaggot->setStartingPosition(885, 277);
		this->addEntities(flaggot);


}