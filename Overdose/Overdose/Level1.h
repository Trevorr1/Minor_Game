#pragma once
#include "Ilevel.h"
namespace overdose {
class Level1 : public ILevel
{
public:
	Level1();
	~Level1();
	void Init();
	void addEntities(GameEntity entities);
	GameEntity* getPlayerEntity();
	void Tick(float a_DT);
	void Render(Surface* surface);
	GameEntity getPlayerEntity(void);
	std::vector<GameEntity> *getEntities();
	void tick(double dt);
private:
	std::vector<GameEntity> *entities;
	Surface* m_Background;
	GameEntity* m_Player;
};

}

