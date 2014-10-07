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
	LevelManager* getInstance();
	ILevel* createLevel(levels level);
	ILevel* getCurrentLevel();
	void tick(double dt);
private:
	LevelManager(void);
	LevelManager* instance;
	ILevel* currentLevel;
};

}

