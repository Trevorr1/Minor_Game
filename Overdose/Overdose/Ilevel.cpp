#include "stdafx.h"
#include "ILevel.h"
#include "GameEntityFactory.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace overdose;

ILevel::ILevel()
{

	m_WorldSizeX = 940;
	m_WorldSizeY = 480;
	//GameEntity *fpsCounter = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	//this->addEntities(fpsCounter);

	createLevel(m_WorldSizeX, m_WorldSizeY); //maybe let this return the created surface?
}

void ILevel::addEntities(GameEntity* entities)
{
	/* //Used this snippet code to get all the objects enum code & position (Bas)
	printf(std::to_string((int)entities->getEnum()).c_str());
	printf(" ");
	printf((std::to_string((int)entities->getPosX())).c_str());
	printf(" ");
	printf((std::to_string((int)entities->getPosY())).c_str());
	printf("\n");
	*/
	this->entities->push_back(entities);
}

void ILevel::scheduleEntityForInsertion(GameEntity* entity) {
	insertEntityBuffer->push_back(entity);
}



void ILevel::removeEntity(GameEntity* entity) 
{
	for (auto &it : *entities) 
	{
		if (entity == it) 
		{
			it = nullptr;
			delete entity;
			entity == nullptr;
		}
	}
}


GameEntity* ILevel::getPlayerEntity()
{
	return m_Player;
}

//Steals the gameEntity, meaning removing it from this level
GameEntity* ILevel::takePlayerEntity()
{
	GameEntity* player = getPlayerEntity();
	player->setSpeedX(0.0f);
	player->setSpeedY(0.0f);
	player->setMovementSpeed(190.0f); /* HARDCODED: Must fix this */

	if (player != nullptr)
	{
		std::vector<GameEntity*>::iterator position = std::find(entities->begin(), entities->end(), player);
		if (position != entities->end()){
			entities->erase(position);
		}

	}

	removeDrugComponents(player);

	return player;
}

void ILevel::setPlayerEntity(GameEntity* player)
{
	m_Player = player;
}


std::vector<GameEntity*>* ILevel::getEntities()
{
	return entities;
}

void ILevel::removeDrugComponents(GameEntity* player){
	for (auto component : *player->getComponentList()){
		if (component->getComponentID().find("DrugComponent") != std::string::npos || component->getComponentID().find("Negative") != std::string::npos){
			player->removeComponent(component->getComponentID());
		}
	}
}

//std::vector<GameEntity*>* ILevel::getCollectibles(){
//	return collectibles;
//}
//
//std::vector<GameEntity*>* ILevel::getEnemies(){
//	return enemies;
//}

void ILevel::DrawBackground()
{
	int levelWidth = m_WorldSizeX;
	int position = 0;
	int positionSteps = m_Background->GetWidth();
	while (levelWidth > 0){
		m_Background->CopyTo(DrawManager::getInstance().getLevelSurface(), position, 0); //copy to origin
		position += positionSteps;
		levelWidth -= positionSteps;
	}
}

void ILevel::Tick(float dt)
{
	DrawBackground();

	// gebufferde entities eerst
	for (auto &it : *insertEntityBuffer) {
		entities->push_back(it);
	}

	insertEntityBuffer->clear();
	
	auto toRemove = std::remove_if(entities->begin(), entities->end(), [](GameEntity* p) {
		if (p->isScheduledForRemoval() && p->getEnum() != eGameEntity::Player) {
			delete p;
			p = nullptr;
			return true;
		}
		return false;
	});

	entities->erase(toRemove, entities->end());

	for (auto &it : *entities) 
	{
		it->tick(dt);
	}
	if (m_Camera != nullptr)
		m_Camera->Tick(dt);

	
	//-After camera Surface is set
	//|***************************************
	if (hud != nullptr){
		hud->tick(dt);
	}

	if (m_FpsCounter != nullptr){
		m_FpsCounter->tick(dt);
	}
	//***************************************|

	//Create Head-up Display if player exists
	if (m_Player != nullptr && hud == nullptr){
		hud = new HUD(m_Player, 20.0f, 20.0f);
	}

	//Create FPS Counter
	if (m_FpsCounter == nullptr){
		m_FpsCounter = GameEntityFactory::getInstance().getGameEntity(eGameEntity::FPSCounter);
	}
	
}

bool ILevel::isGameOver() 
{
	return m_Player->isScheduledForRemoval();
}

void ILevel::createLevel(int width, int height)
{
	DrawManager::getInstance().createLevelSurface(width, height);
}

bool ILevel::isGameWon() 
{
	return m_IsGameWon;
}

void ILevel::setGameWon()
{
	m_IsGameWon = true;
}

bool ILevel::isReloadLevel() 
{
	return m_IsReloadLevel;
}

void ILevel::setReloadLevel()
{
	m_IsReloadLevel = true;
}

ILevel::~ILevel() 
{
	printf("Level unloaded from the game.\n");
	delete m_Camera;
	//delete m_Player;

	while (!entities->empty()) 
	{
		delete entities->back();
		entities->pop_back();
	}

	delete entities;

	while (!insertEntityBuffer->empty()) {
		delete insertEntityBuffer->back();
		insertEntityBuffer->pop_back();
	}

	delete insertEntityBuffer;

	delete hud;
	delete m_FpsCounter;

	Surface::flushImageCache();
}




void ILevel::loadXML(int level){

	std::string line;
	int enemy;
	int x;
	int y;

	const std::string textfile("assets/levels/level" + std::to_string(level) + ".txt");
	// input file stream, opent textfile voor lezen
	std::ifstream input_file(textfile);

	while (getline(input_file, line)){
		if ((line[0] == '/') &&
			(line[1] == '/')){
			continue;
		}
		else if (line == ""){
			continue;
		}
		
		std::istringstream iss(line);
		std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
		enemy = atoi(tokens.at(0).c_str());
		x = atoi(tokens.at(1).c_str());
		y = atoi(tokens.at(2).c_str());

		GameEntity* GameEntity = GameEntityFactory::getInstance().getGameEntity((eGameEntity)enemy);
		GameEntity->setStartingPosition(x, y);
		this->addEntities(GameEntity);

	}
}