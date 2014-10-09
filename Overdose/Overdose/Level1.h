#pragma once
#include "Ilevel.h"
namespace overdose {
class Level1 : public ILevel
{
public:
	Level1();
	~Level1();
	void Init();
	void addEntities(GameEntity* entities);
	void addEnemies(GameEntity* entities);
	void addCollectibles(GameEntity* entities);
	GameEntity* getPlayerEntity();
	std::vector<GameEntity*> *getEntities();
	std::vector<GameEntity*> *getEnemies();
	std::vector<GameEntity*> *getCollectibles();
	void Tick(float a_DT);
private:
	std::vector<GameEntity*> *enemies;
	std::vector<GameEntity*> *collectibles;
	void DrawBackground();
};

}

