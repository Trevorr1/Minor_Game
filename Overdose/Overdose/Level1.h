#pragma once
#include "Ilevel.h"
namespace overdose {
class Level1 : public ILevel
{
public:
	Level1(void);
	~Level1(void);
	void Init();
	void addEntities(GameEntity entities);
private:
	std::vector<GameEntity> *entities;
};

}

