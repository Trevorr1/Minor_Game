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
	LevelManager(void);
	~LevelManager(void);
	ILevel* createLevel(levels level);
private:
	ILevel* currentLevel;
};

}

