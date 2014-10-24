#include "stdafx.h"
#include "Level2.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;


/*Test Data*/
//GameEntity* entityPtr = nullptr;

Level2::Level2()
{
	entities = new std::vector<GameEntity*>();
	enemies = new std::vector<GameEntity*>();
	collectibles = new std::vector<GameEntity*>();
	m_Background = new Surface("assets/backgrounds/background.png");

}


Level2::~Level2()
{
	for (int i = entities->size(); i >= 0; i--)
	{
		delete entities->at(i);
	}
	delete entities;
}

void Level2::Init()
{
	/*Test Data*/
	GameEntity *fpsCounter = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::FPSCounter);
	this->addEntities(fpsCounter);

	GameEntity *player = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Player);
	player->setPosX(100);
	player->setPosY(0);
	this->addEntities(player);
	m_Player = player;
	
	int grassWall = 22;
	for (int i = 0; i < grassWall; i++){
		/*if (i > (grassWall/2 - 2) && i < (grassWall/2 + 2)){
		continue;
		}*/
		GameEntity* grass1 = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Grass);
		grass1->setPosX(50 + 32 * i);
		grass1->setPosY(100 + 16 * i);
		this->addEntities(grass1);
	}

	GameEntity *flaggot = GameEntityFactory::getInstance()->getGameEntity(eGameEntity::Flag);
	flaggot->setPosX(700);
	flaggot->setPosY(410 - 112);
	this->addEntities(flaggot);


}
