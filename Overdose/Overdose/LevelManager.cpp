#include "stdafx.h"
#include "LevelManager.h"
#include "Level1.h"

using namespace overdose;
LevelManager::LevelManager(void)
{
	currentLevel = nullptr;
}


LevelManager::~LevelManager(void)
{
	delete instance;
}

ILevel* LevelManager::getCurrentLevel()
{
	return currentLevel;
}

LevelManager* LevelManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new LevelManager();
		return instance;
	}
	else
	{
		return instance;
	}
}


ILevel* LevelManager::createLevel(levels l)
{
	switch(l){
	case(level1):
		currentLevel = new Level1();
		currentLevel->Init();
	}
	currentLevel->getPlayerEntity();
	return currentLevel;
}

void LevelManager::tick(double dt)
{
	currentLevel->tick(dt);
}

