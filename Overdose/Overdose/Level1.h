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
	GameEntity getPlayerEntity(void);
	std::vector<GameEntity> *getEntities();
	void tick(double dt);
private:
	std::vector<GameEntity> *entities;
	GameEntity *player;
};

}

