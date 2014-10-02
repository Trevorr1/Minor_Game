#include "Factory.h"
#include "MoveComponent.h"
#include "DummyComponent.h"

using namespace overdose;

Factory* Factory::_instance = nullptr;

Factory::Factory()
{
}

Factory* Factory::getInstance(){
	if (_instance == nullptr){
		_instance = new Factory;
	}
	return _instance;
}

GameEntity* Factory::getGameEntity(eGameEntity entityEnum){

	GameEntity* newObject = new GameEntity();

	switch (entityEnum){
	case Policeman:
		newObject->addComponent(*new DummyComponent());
		break;
	case Drugdealer:
		newObject->addComponent(*new DummyComponent());
		break;
	case DrugAddict:
		newObject->addComponent(*new MoveComponent());
		break;
	}

	return newObject;
}


Factory::~Factory()
{
	delete _instance;
}
