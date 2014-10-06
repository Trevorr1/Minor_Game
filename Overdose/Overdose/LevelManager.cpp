#include "stdafx.h"
#include "LevelManager.h"
#include "Level1.h"

using namespace overdose;
LevelManager::LevelManager(void)
{
}


LevelManager::~LevelManager(void)
{
}

ILevel* LevelManager::createLevel(levels l)
{
	ILevel *currentLevel = nullptr;
	switch(l){
	case(level1):
		currentLevel = new Level1();
	}

	return currentLevel;
}

