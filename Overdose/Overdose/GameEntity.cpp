#include "stdafx.h"

using std::vector;
using namespace overdose;

vector<Component> *compontentList = new vector<Component>();


/* Add component to the list */
void GameEntity::addComponent(Component component) {

	compontentList->push_back(component);
}

void GameEntity::tick() {
	for (vector<Component>::iterator it = compontentList->begin(); it != compontentList->end(); it++) {
		it->tick(*this);
	}
}

GameEntity::GameEntity() {


}

GameEntity::~GameEntity() {
	delete compontentList;
}
