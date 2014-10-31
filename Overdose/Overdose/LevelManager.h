#pragma once
#include "ILevel.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "GameWon.h"
#include "Level1.h"
#include "Level2.h"
namespace overdose {
enum levels{
	LevelMainMenu,
	level1,
	level2,
	LevelGameWon,
	LevelGameOver
};

class LevelManager
{
	public:
		~LevelManager(void);
		static LevelManager* getInstance();
		ILevel* createLevel(levels level);
		ILevel* getCurrentLevel();
		void LevelManager::Tick(float dt);
	private:
		ILevel* currentLevel = nullptr;
		ILevel* previousLevel = nullptr;
		levels currentLevelEnum;
		LevelManager(void);
		static LevelManager* _instance;
		void nextLevel();
	};

}

