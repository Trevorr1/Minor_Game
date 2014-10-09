#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "Factory.h"

using namespace overdose;


/*Test Data*/
GameEntity* entityPtr = nullptr;

Level1::Level1()
{
	entities = new std::vector<GameEntity>();
	enemies = new std::vector<GameEntity>();
	collectibles = new std::vector<GameEntity>();
	m_Background = new Surface("assets/backgrounds/background.jpg");
}


Level1::~Level1()
{
	delete entities;
}

void Level1::addEntities(GameEntity* entities)
{
	this->entities->push_back(*entities);
}

void Level1::addEnemies(GameEntity* entities)
{
	this->enemies->push_back(*entities);
}

void Level1::addCollectibles(GameEntity* entities)
{
	this->collectibles->push_back(*entities);
}

void Level1::Init()
{
	/*Test Data*/
	entityPtr = GameEntityFactory::getInstance()->getGameEntity(DrugAddict);
	entityPtr->setSpeedY(0);
	//this->addEntities(entityPtr);

	GameEntity *entityPtr1 = GameEntityFactory::getInstance()->getGameEntity(DrugAddict);
	entityPtr1->setPosY(50);
	entityPtr1->setSpeedY(0);
	this->addEntities(entityPtr1);
}
void Level1::Tick(float dt){
	DrawBackground();
	/*Test Data*/
	entityPtr->tick();
}

void Level1::DrawBackground(){
	m_Background->CopyTo(DrawManager::getInstance()->getSurface(), 0, 0);
}

GameEntity* Level1::getPlayerEntity(){
	return m_Player;
}

std::vector<GameEntity>* Level1::getEntities(){
	return entities;
}

std::vector<GameEntity>* Level1::getCollectibles(){
	return collectibles;
}

std::vector<GameEntity>* Level1::getEnemies(){
	return enemies;
}
