#include "stdafx.h"
#include "LevelManager.h"
#include "SoundManager.h"
#include "InputManager.h"
#include "HighScore.h"
#include "SaveGameManager.h"
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

ILevel* LevelManager::createLevel(levels l, GameEntity* player)
{
	previousLevel = currentLevel;
	currentLevelEnum = l;
	currentLevel = createNewLevel(l);
	if (player != nullptr){
		player->resetGravity();
		currentLevel->setPlayerEntity(player);
	}
	currentLevel->Init();
	return currentLevel;
}


ILevel* LevelManager::createNewLevel(levels l)
{
	ILevel* result;
	switch (l){
	case level1:
		result = new Level1();
		break;
	case level2:
		result = new Level2();
		break;
	case level3:
		result = new Level3();
		break;
	case level4:
		result = new Level4();
		break;
	case level6:
		result = new Level6();
		break;
	case level7:
		result = new Level7();
		break;
	case level8:
		result = new Level8();
		break;
	case LevelBossFight:
		result = new LevelBoss();
		break;
	case LevelMainMenu:
		result = new MainMenu();
		break;
	case LevelGameOver:
		result = new GameOver();
		break;
	case LevelGameWon:
		result = new GameWon();
		break;
	case LevelCredits:
		result = new Credits();
		break;
	case LevelLoadGame:
		result = new LoadGame();
		break;
	case LevelHighScore:
		result = new HighScore();
		break;
	case LevelOptions:
		result = new Options();
		break;
	case LevelOptionsControls:
		result = new OptionsControls();
		break;
	case LevelOptionsDrugs:
		result = new OptionsDrugs();
		break;
	case LevelOptionsGeneral:
		result = new OptionsGeneral();
		break;
	default:
		throw std::invalid_argument("Invalid level enum");
		break;
	}

	return result;
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
		reloadLevel(currentLevel->takePlayerEntity());
	}
	
	if (previousLevel != nullptr) 
	{
		delete previousLevel;
		previousLevel = nullptr;
	}

	if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_PAGEUP) && m_SpeedModifier <= 1.5) {
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
	else if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_F2)) {
		SaveGame game;
		game.savedLevelId = currentLevelEnum;
		SaveGameManager::getInstance().save(game);
	}
	else if (InputManager::getInstance().isKeyPressedOnce(SDL_SCANCODE_F3) && currentLevel != nullptr) {
		
		if (currentLevel->getPlayerEntity() != nullptr) {
			printf("Player position:\n");
			std::cout << "X-Pos: " << currentLevel->getPlayerEntity()->getPosX() << '\n';
			std::cout << "Y-Pos: " << currentLevel->getPlayerEntity()->getPosY() << '\n';
		}
	}
	currentLevel->Tick(dt * m_SpeedModifier);
}

LevelManager &LevelManager::getInstance()
{
	static LevelManager _instance;
	return _instance;
}

void LevelManager::nextLevel(GameEntity* player)
{
	//even lelijk:
	//to do, remove all levels
	//Ricardo :D
	switch (currentLevelEnum){
	case LevelMainMenu:
		createLevel(level1);
		break;
	case level1:
		createLevel(level2);
		break;
	case level2:
		createLevel(level3);
		break;
	case level3:
		createLevel(level4);
		break;
	case level4:
		createLevel(level6);
		break;
	case level6:
		createLevel(level7);
		break;
	case level7:
		createLevel(level8);
		break;
	case level8:
		createLevel(LevelBossFight);
		break;
	case LevelBossFight:
		createLevel(LevelGameWon);
		break;
	case LevelHighScore:
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


void LevelManager::reloadLevel(GameEntity* player)
{
	createLevel(currentLevelEnum, player);
}
