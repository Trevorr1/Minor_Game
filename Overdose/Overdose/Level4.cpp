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

	/* Blocks: */
	int xOffset = 0;
	int blocksWidth = 0;

	//addGrassBlock(0, 480 - 32 * 1, 232, 1);//debug wall

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 5);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 6;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 4;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 3;//whitespace

	blocksWidth = 4;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	GameEntity *entityDrugSpeed1 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Marijuana);
	entityDrugSpeed1->setStartingPosition(32 * (xOffset - 2), 480 - 32 * 8 - 30);
	entityDrugSpeed1->setSpeedX(0);
	entityDrugSpeed1->setSpeedY(0);
	this->addEntities(entityDrugSpeed1);

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 11, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 12, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 13, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 14, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 6;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 5); // muurtje
	xOffset -= 2;

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset -= 1;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset -= 1;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset -= 1;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 2);
	xOffset -= 2;

	blocksWidth = 22;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 1); //start run-lane
	xOffset += blocksWidth;

	GameEntity *entityDrugSpeed = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Drug_Speed);
	entityDrugSpeed->setStartingPosition(32 * (xOffset - 12), 480 - 32 * 3  - 30);
	entityDrugSpeed->setSpeedX(0);
	entityDrugSpeed->setSpeedY(0);
	this->addEntities(entityDrugSpeed);

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 2);
	xOffset += blocksWidth;

	blocksWidth = 22;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 3);
	xOffset += blocksWidth;

	blocksWidth = 22;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 4);
	xOffset += blocksWidth;

	blocksWidth = 11;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 4, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 5;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 11, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 3);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 12, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 3;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 2);
	xOffset += blocksWidth;

	blocksWidth = 5;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 11, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 7;
	addGrassBlock(32 * xOffset, 480 - 32 * 10, blocksWidth, 1);

	/*cop*/
	GameEntity* entityCop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Policeman);
	entityCop->setStartingPosition(32 * xOffset, 480 - 32 * 10 - 54);
	entityCop->addComponent(new EnemyMoveComponent(10 + 32 * xOffset, 32 * (xOffset + 6) - 10));
	this->addEntities(entityCop);
	xOffset += blocksWidth;

	blocksWidth = 2;
	addGrassBlock(32 * xOffset, 480 - 32 * 11, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 11, blocksWidth, 3);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 3);
	xOffset += blocksWidth;

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	xOffset -= 38;//go back

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 5, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 4, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 3, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 38;
	addGrassBlock(32 * xOffset, 480 - 32 * 2, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 2, blocksWidth, 5);
	xOffset += blocksWidth;

	xOffset += 2;//whitespace

	blocksWidth = 3;
	addGrassBlock(32 * xOffset, 480 - 32 * 6, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 7, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 8, blocksWidth, 1);
	xOffset += blocksWidth;

	blocksWidth = 1;
	addGrassBlock(32 * xOffset, 480 - 32 * 9, blocksWidth, 1);
	xOffset += blocksWidth;
	
	xOffset += 3;//whitespace

	blocksWidth = 4;
	addGrassBlock(32 * xOffset, 480 - 32 * 11, blocksWidth, 1);
	xOffset += blocksWidth;
	
	GameEntity *flaggot2 = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Flag);
	flaggot2->setStartingPosition(32 * (xOffset-1) - 29, 480 - 32 * 11 - 111);
	this->addEntities(flaggot2);





	




	SoundManager::getInstance().StopMusic();
	SoundManager::getInstance().PlayMusic(eMusic::Street);
	//SoundManager::getInstance()->PlaySound(eSound::Death);
}
