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

	if (currentLevel != nullptr){
		//delete currentLevel; //weet niet waarom maar dit ging nog even fout
	}

	switch (l){
	case level1:
		currentLevel = new Level1();
		break;
	case level2:
		currentLevel = new Level2();
		break;
	case LevelMainMenu:
		currentLevel = new MainMenu();
		break;

	case LevelGameOver:
		currentLevel = new GameOver();
		break;
	case LevelGameWon:
		currentLevel = new GameWon();
		break;
	default:
		throw std::invalid_argument("Invalid level enum");
		break;
	}

	currentLevelEnum = l;
	currentLevel->Init();
	return currentLevel;
}

void LevelManager::Tick(float dt){
	if (currentLevel->isGameOver()) {
		createLevel(levels::LevelGameOver);
	}
	else if (currentLevel->isGameWon()){
		nextLevel();
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

void LevelManager::nextLevel(){
	//even lelijk:
	switch (currentLevelEnum){
	case LevelMainMenu:
		createLevel(level1);
		break;
	case level1:
		createLevel(level2);
		break;
	case level2:
		createLevel(LevelGameWon);
		break;
	case LevelGameOver:
		createLevel(LevelMainMenu);
		break;
	case LevelGameWon:
		createLevel(LevelMainMenu);
		break;
	}
	
}