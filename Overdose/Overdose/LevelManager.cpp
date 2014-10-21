#include "stdafx.h"
#include "LevelManager.h"

using namespace overdose;

LevelManager* LevelManager::_instance = nullptr;

LevelManager::LevelManager(void)
{
	std::cout << "Succesfully initialised LevelManager" << std::endl;
	createLevel(LevelMainMenu);
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
	switch (l){
	case level1:
		if (currentLevel != nullptr){
			//delete currentLevel; //weet niet waarom maar dit ging nog even fout
		}
		currentLevel = new Level1();

		//currentLevel->getPlayerEntity();//wist niet waarom deze regel moest, dus heb 'm eruit gecomment =( uncomment als hij terug moet!
		break;
	case LevelMainMenu:
		currentLevel = new MainMenu();
		break;

	case LevelGameOver:
		currentLevel = new GameOver();
		break;
	}
	
	currentLevel->Init();
	return currentLevel;
}

void LevelManager::Tick(float dt){
	if (currentLevel->isGameOver()) {
		createLevel(levels::LevelGameOver);
	}
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