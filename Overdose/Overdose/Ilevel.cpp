#include "stdafx.h"
#include "ILevel.h"

using namespace overdose;

void ILevel::addEntities(GameEntity* entities)
{
	this->entities->push_back(entities);
}

void ILevel::addEnemies(GameEntity* entities)
{
	this->enemies->push_back(entities);
}

void ILevel::addCollectibles(GameEntity* entities)
{
	this->collectibles->push_back(entities);
}

GameEntity* ILevel::getPlayerEntity(){
	return m_Player;
}

std::vector<GameEntity*>* ILevel::getEntities(){
	return entities;
}

std::vector<GameEntity*>* ILevel::getCollectibles(){
	return collectibles;
}

std::vector<GameEntity*>* ILevel::getEnemies(){
	return enemies;
}

void ILevel::DrawBackground(){
	m_Background->CopyTo(DrawManager::getInstance()->getSurface(), 0, 0);
}

void ILevel::Tick(float dt){
	DrawBackground();
	/*Test Data*/
	for (auto &it : *entities) {
		it->tick(dt);
	}
}