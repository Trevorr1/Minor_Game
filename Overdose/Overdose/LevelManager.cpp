#include "stdafx.h"
#include "LevelManager.h"
#include "Level1.h"

using namespace overdose;
LevelManager::LevelManager(void)
{
	setLevel(level1);
}


LevelManager::~LevelManager(void)
{
}

void LevelManager::setLevel(levels l)
{
	switch(l){
	case(level1) :
		if (currentLevel != nullptr){
			//delete currentLevel; //zo toch?
		}
		currentLevel = new Level1();
		currentLevel->Init();
		break;
	}
}

void LevelManager::Tick(float dt){
	currentLevel->Tick(dt);
}

void LevelManager::Render(Surface* surface){
	currentLevel->Render(surface);
}

