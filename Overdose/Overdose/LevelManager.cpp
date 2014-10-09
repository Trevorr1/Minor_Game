#include "stdafx.h"
#include "LevelManager.h"
#include "Level1.h"

using namespace overdose;

LevelManager* LevelManager::_instance = nullptr;

LevelManager::LevelManager(void)
{
	createLevel(level1);
}

LevelManager::~LevelManager(void)
{
	delete currentLevel;
}

ILevel* LevelManager::getCurrentLevel(){
	return currentLevel;
}

ILevel* LevelManager::createLevel(levels l)
{
	switch(l){
	case(level1) :
		if (currentLevel != nullptr){
		//delete currentLevel; //weet niet waarom maar dit ging nog even fout
		}
		currentLevel = new Level1();
		currentLevel->Init(); 
		//currentLevel->getPlayerEntity();//wist niet waarom deze regel moest, dus heb 'm eruit gecomment =( uncomment als hij terug moet!
		break;
	}
	return currentLevel;
}

void LevelManager::Tick(float dt){
	currentLevel->Tick(dt);
}



LevelManager* LevelManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new LevelManager();
	}
	return _instance;
}