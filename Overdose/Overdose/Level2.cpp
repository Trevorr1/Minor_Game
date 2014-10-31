#include "stdafx.h"
#include "Level2.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;

Level2::Level2()
{
	m_Background = new Surface("assets/backgrounds/background.png");

}


Level2::~Level2()
{
	delete m_Background;
}

void Level2::Init()
{
	/*Test Data*/
	GameEntity *fpsCounter = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);

	GameEntity *player = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Player);
	player->setStartingPosition(100, 0);
	this->addEntities(player);
	m_Player = player;
	
	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		/*if (i > (grassWall/2 - 2) && i < (grassWall/2 + 2)){
		continue;
		}*/
		GameEntity* grass1 = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Grass);
		grass1->setStartingPosition(50 + 32 * i, 100 + 16 * i);
		this->addEntities(grass1);
	}

	GameEntity *flaggot = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Flag);
	flaggot->setStartingPosition(700, 410 - 112);
	this->addEntities(flaggot);


}
