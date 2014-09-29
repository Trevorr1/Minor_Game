#include "stdafx.h"

using std::vector;
using namespace overdose;

vector<Component> *compontentList = new vector<Component>();


/* Add component to the list */
void ComponentContainer::addComponent(Component component) {

	compontentList->push_back(component);
}

void ComponentContainer::tick() {
	for (vector<Component>::iterator it = compontentList->begin(); it != compontentList->end(); it++) {
		it->tick(*this);
	}
}

ComponentContainer::ComponentContainer() {


}

ComponentContainer::~ComponentContainer() {
	delete compontentList;
}
