#include "Factory.h"
#include "MoveComponent.h"
#include "DummyComponent.h"
#include "EnemyMoveComponent.h"
#include "CollisionComponent.h"
#include "DrawComponent.h"
#include "FPSDrawComponent.h"
#include "PlayerInputComponent.h"
#include <stdexcept>
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
		newObject->addComponent(new EnemyMoveComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new DrawComponent("assets/sprites/cop.png", 1));
		newObject->addComponent(new CollisionComponent());
		newObject->setSpeedX(-1);
		break;
	case Drugdealer:
		//	newObject->addComponent(*new DummyComponent());
		break;
	case FPSCounter:
		newObject->addComponent(new FPSDrawComponent());
		break;
	case DrugAddict:
		newObject->addComponent(new PlayerInputComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new DrawComponent("assets/bottom_enemy_anim.tga", 3));

		break;
	default:
		throw std::invalid_argument("Invalid game Entity passed to the factory"); // Veel te lang moeten debuggen waarom mij entities geen components hadden... >.<
	}

	return newObject;
}


GameEntityFactory::~GameEntityFactory()
{
	delete _instance;
}
