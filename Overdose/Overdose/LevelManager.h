#pragma once
#include "ILevel.h"
namespace overdose {
enum levels{
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
		void LevelManager::Render(Surface* surface);
	private:
		ILevel* currentLevel;
		LevelManager(void);
		static LevelManager* _instance;
	};

}

