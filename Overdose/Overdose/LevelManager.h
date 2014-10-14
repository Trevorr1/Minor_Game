#pragma once
#include "ILevel.h"
#include "MainMenu.h"
#include "Level1.h"
namespace overdose {
enum levels{
	LevelMainMenu,
	level1,
	level2,
	level3
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
		ILevel* currentLevel;
		LevelManager(void);
		static LevelManager* _instance;
	};

}

