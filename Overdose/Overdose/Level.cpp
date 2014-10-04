#include "Level.h"
using namespace overdose;

vector<GameEntity*> Level::getGameEntities() {
	return *entityList;
}