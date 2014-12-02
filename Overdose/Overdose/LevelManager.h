#pragma once

#include "ILevel.h"
#include "MainMenu.h"
#include "GameOver.h"
#include "GameWon.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Credits.h"
#include "LoadGame.h"

namespace overdose {
enum levels{
	LevelMainMenu,
	LevelCredits,
	level1,
	level2,
	level3,
	level4,
	level5,
	level6,
	level7,
	level8,
	level9,
	level10,
	LevelGameWon,
	LevelGameOver,
	LevelHighScore,
	LevelLoadGame
};

class LevelManager
{
	public:
		~LevelManager(void);
		static LevelManager &getInstance();
		ILevel* createLevel(levels level, GameEntity* player = nullptr);
		ILevel* getCurrentLevel();
		void LevelManager::Tick(float dt);
		void reloadLevel(GameEntity* player = nullptr);
		void nextLevel(GameEntity* player = nullptr);
		float getSpeedModifier() { return m_SpeedModifier; }
	private:
		ILevel* currentLevel = nullptr;
		ILevel* previousLevel = nullptr;
		levels currentLevelEnum;
		LevelManager(void);
		static LevelManager* _instance;
		float m_SpeedModifier = 1;

		ILevel* createNewLevel(levels level);

	};

}

