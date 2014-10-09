#include "Factory.h"
#include "MoveComponent.h"
#include "DummyComponent.h"
#include "DrawComponent.h"
#include "PlayerInputComponent.h"

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

	GameEntity* newObject = new GameEntity(entityEnum);

	switch (entityEnum){
	case Policeman:
	//	newObject->addComponent(*new DummyComponent());
		break;
	case Drugdealer:
	//	newObject->addComponent(*new DummyComponent());
		break;
	case DrugAddict:
		newObject->addComponent(*new PlayerInputComponent());
		newObject->addComponent(*new MoveComponent());
		newObject->addComponent(*new DrawComponent("assets/bottom_enemy_anim.tga", 3));
		
		break;
	}

	return newObject;
}


Factory::~Factory()
{
	delete _instance;
}
