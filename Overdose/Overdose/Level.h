#pragma once
#include "stdafx.h"
#include "GameEntity.h"
using namespace std;

namespace overdose {

	class GameEntity;
	class Level {

	protected:
		vector<GameEntity*> *entityList = new vector<GameEntity*>();

	public:

		vector<GameEntity*> getGameEntities();
	};
}