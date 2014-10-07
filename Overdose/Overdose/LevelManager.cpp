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
}

ILevel* LevelManager::createLevel(levels l)
{
	switch(l){
	case(level1):
		currentLevel = new Level1();
		currentLevel->Init();
	}

	return currentLevel;
}

