#include "Factory.h"
#include "MoveComponent.h"
#include "DummyComponent.h"
#include "DrawComponent.h"
#include "PlayerInputComponent.h"

using namespace overdose;

GameEntityFactory* GameEntityFactory::_instance = nullptr;

GameEntityFactory::GameEntityFactory()
{
}

GameEntityFactory* GameEntityFactory::getInstance(){
	if (_instance == nullptr){
		_instance = new GameEntityFactory;
	}
	return _instance;
}

GameEntity* GameEntityFactory::getGameEntity(eGameEntity entityEnum){

	GameEntity* newObject = new GameEntity(entityEnum);

	switch (entityEnum){
	case Policeman:
	//	newObject->addComponent(*new DummyComponent());
		break;
	case Drugdealer:
	//	newObject->addComponent(*new DummyComponent());
		break;
	case DrugAddict:
		newObject->addComponent(new PlayerInputComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new DrawComponent("assets/bottom_enemy_anim.tga", 3));
		
		break;
	}

	return newObject;
}


GameEntityFactory::~GameEntityFactory()
{
	delete _instance;
}
