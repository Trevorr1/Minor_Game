#include "stdafx.h"
#include "Level5.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "EnemyMoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level5::Level5()
{
}

Level5::Level5(GameEntity* player)
{
	m_Player = player;
}

Level5::~Level5()
{
	delete m_Background;
}

void Level5::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");

	if (m_Player == nullptr){
		GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
		m_Player = player;
	}

	this->addEntities(m_Player);
	m_Player->setStartingPosition(100, 410 - 53 - 100);

	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(500, 410 - 54 - 96);
	entityCop->addComponent(new EnemyMoveComponent(360, 630));
	this->addEntities(entityCop);

	GameEntity* entityCop2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop2->setStartingPosition(400, 410 - 54 - 96);
	entityCop->addComponent(new EnemyMoveComponent(360, 630));
	this->addEntities(entityCop2);

	int grassWall = 4;
	for (int i = 0; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);

		if (i == 3){
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * i, 410-32);
			this->addEntities(grass1);
		}

	}

	grassWall = 18;
	for (int i = 0; i < grassWall; i++){
		if (i > 3){
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * i, 410 - 32 *3);
			this->addEntities(grass1);
		}

		
	}
	grassWall = 22;
	for (int i = 18; i < grassWall; i++){
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 410);
		this->addEntities(grass1);

		if (i == 18){
			GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
			grass1->setStartingPosition(50 + 32 * i, 410 - 32);
			this->addEntities(grass1);
		}

	}

	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 410 - 112);
	this->addEntities(flaggot);

}