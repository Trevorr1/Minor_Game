#include "GameEntityFactory.h"
#include "MoveComponent.h"
#include "DummyComponent.h"
#include "EnemyMoveComponent.h"
#include "CollisionComponent.h"
#include "DrawComponent.h"
#include "FPSDrawComponent.h"
#include "PlayerInputComponent.h"
#include "ClickableComponent.h"
#include "gravityComponent.h"
#include "CollisionReactionComponent.h"
#include "PlayerCollisionReactionComponent.h"
#include "PolicemanCollisionReactionComponent.h"
#include "DrugCollisionReactionComponent.h"
#include "ButtonClickableReactionComponent.h"
#include "HealthComponent.h"
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
	std::map<eAnimationState, Animation*>* animations = new std::map<eAnimationState, Animation*>();
	DrawComponent* animation = nullptr;

	switch (entityEnum){
	case Policeman:
		newObject->setSpeedX(0.05f);
		//	newObject->addComponent(*new DummyComponent());
		newObject->addComponent(new EnemyMoveComponent());
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new PlayerCollisionReactionComponent());//moet nog verandert worden naar PolicemanCollisionReactionComponent
		newObject->addComponent(new gravityComponent());
	//	newObject->addComponent(new CollisionComponent());

		animations->insert({ WalkLeft, new Animation("assets/sprites/Policeman/PolicemanWalkLeft.png", 4, 5) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Policeman/PolicemanWalkRight.png", 4, 5) });
		animation = new DrawComponent(animations);
		animation->setAnimation(WalkLeft);//set default animation
		newObject->addComponent(animation);
		break;
	case Drugdealer:
		//	newObject->addComponent(*new DummyComponent());
		break;
	case FPSCounter:
		newObject->addComponent(new FPSDrawComponent());
		break;
	case Player:
		newObject->setMovementSpeed(0.2f);
		newObject->addComponent(new PlayerInputComponent());
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new PlayerCollisionReactionComponent());
		newObject->addComponent(new gravityComponent());
		newObject->addComponent(new HealthComponent(3));

		animations->insert({ IdleLeft, new Animation("assets/sprites/Ross/RossIdleLeft.png", 1) });
		animations->insert({ IdleRight, new Animation("assets/sprites/Ross/RossIdleRight.png", 1) });
		animations->insert({ WalkLeft, new Animation("assets/sprites/Ross/RossWalkingLeft.png", 8, 10) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Ross/RossWalkingRight.png", 8, 10) });
		animation = new DrawComponent(animations);
		animation->setAnimation(IdleRight);//set default animation
		newObject->addComponent(animation);
		break;
	case ButtonPlay:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));

		animations->insert({ Default, new Animation("assets/buttons/button_play.jpg", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set default animation
		newObject->addComponent(animation);
		break;
	case Drug_Speed:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());

		animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set default animation
		newObject->addComponent(animation);
		break;
	case Grass:
		newObject->addComponent(new CollisionComponent());

		animations->insert({ Default, new Animation("assets/sprites/grass.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set default animation
		newObject->addComponent(animation);
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
