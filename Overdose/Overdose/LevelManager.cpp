#include "stdafx.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "InputManager.h"
using namespace overdose;

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
	GameEntity* player = nullptr;
	previousLevel = currentLevel;

	switch (l){
	case level1:
		currentLevel = new Level1();
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
	case LevelCredits:
		currentLevel = new Credits();
		break;
	default:
		throw std::invalid_argument("Invalid level enum");
		break;
	}

	currentLevelEnum = l;
	currentLevel->Init();

	return currentLevel;
}

void LevelManager::Tick(float dt)
{
	if (currentLevel->isGameOver()) 
	{
		createLevel(levels::LevelGameOver);
	}
	else if (currentLevel->isGameWon())
	{
		nextLevel();
	}
	else if (currentLevel->isReloadLevel())
	{
		reloadLevel();
	}
	
	if (previousLevel != nullptr) 
	{
		delete previousLevel;
		previousLevel = nullptr;
	}

	if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_PAGEUP) && m_SpeedModifier <= 2.5) {
		SoundManager::getInstance().PlaySound1(Click);
		m_SpeedModifier += 0.1;
}

	else if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_PAGEDOWN) && m_SpeedModifier >= 0.5) {
		SoundManager::getInstance().PlaySound1(Click);
		m_SpeedModifier -= 0.1;
	}
	else if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_HOME)) {
		SoundManager::getInstance().PlaySound1(Click);
		m_SpeedModifier = 1;
	}
	currentLevel->Tick(dt * m_SpeedModifier);
}

LevelManager &LevelManager::getInstance()
{
	static LevelManager _instance;
	return _instance;
}

void LevelManager::nextLevel()
{
	//even lelijk:
	//to do, remove all levels
	//Ricardo :D
	switch (currentLevelEnum){
	case LevelMainMenu:
		createLevel(level1);
		break;
	case level1:
		createLevel(LevelGameWon);
		break;
	case level2:
		createLevel(level3);
		break;
	case level3:
		createLevel(level4);
		break;
	case level4:
		createLevel(level5);
		break;
	case level5:
		createLevel(level6);
		break;
	case level6:
		createLevel(level7);
		break;
	case level7:
		createLevel(level8);
		break;
	case level8:
		createLevel(level9);
		break;
	case level9:
		createLevel(level10);
		break;
	case level10:
		createLevel(LevelGameWon);
		break;
	case SetHighScore:
		createLevel(LevelMainMenu);
		break;
	case LevelGameOver:
		createLevel(LevelMainMenu);
		break;
	case LevelGameWon:
		createLevel(LevelMainMenu);
		break;
	}
}

void LevelManager::reloadLevel()
{
	createLevel(currentLevelEnum);
}
