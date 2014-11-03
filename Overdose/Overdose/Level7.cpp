#include "stdafx.h"
#include "Level7.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level7::Level7()
{
}

Level7::Level7(GameEntity* player)
{
	m_Player = player;
}

Level7::~Level7()
{
	delete m_Background;
}

void Level7::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr){
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);
	m_Player->setStartingPosition(100, 310 - 53 - 100);
	
	GameEntity *entityDrugXTC = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_XTC);
	entityDrugXTC->setStartingPosition(200, 410 - 30);
	entityDrugXTC->setSpeedX(0);
	entityDrugXTC->setSpeedY(0);
	this->addEntities(entityDrugXTC);

	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		if (i>3 && i <6 || i>15 && i <18){
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * i, 410);
			this->addEntities(grass1);
		}
		else{
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * i, 350);
			this->addEntities(grass1);
		}
	}

	GameEntity* entityCop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop2->setStartingPosition(35 + 32 * 17, 400 - 54);
	this->addEntities(entityCop2);

	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 350 - 112);
	this->addEntities(flaggot);

}