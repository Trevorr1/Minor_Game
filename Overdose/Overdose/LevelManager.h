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
	void setLevel(levels level);
	void LevelManager::Tick(float dt);
	void LevelManager::Render(Surface* surface);

private:
	ILevel* currentLevel;
};

}

