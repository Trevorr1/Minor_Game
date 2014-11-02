#include "stdafx.h"
#include "Level3.h"
#include "PlayerInputComponent.h"
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level3::Level3()
{
	m_Background = new Surface("assets/backgrounds/background.png");
}


Level3::~Level3()
{
	delete m_Background;
}

void Level3::Init()
{

	GameEntity *player = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Player);
	player->setStartingPosition(100, 410 - 53 - 100);
	this->addEntities(player);
	m_Player = player;

	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		/*if (i > (grassWall/2 - 2) && i < (grassWall/2 + 2)){
		continue;
		}*/
		GameEntity* grass1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 452 - 16 * i);
		this->addEntities(grass1);
	}


	GameEntity *flaggot = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(695, 20);
	this->addEntities(flaggot);

}
