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
#include "QuitOnClickComponent.h"
#include "HealthComponent.h"
#include "FlagCollisionReactionComponent.h"
#include "TextBoxInputComponent.h"
#include "KnockBackComponent.h"
#include "ParticleComponent.h"
#include <stdexcept>
using namespace overdose;


GameEntityFactory::GameEntityFactory()
{
}

GameEntityFactory &GameEntityFactory::getInstance(){
	static GameEntityFactory _instance;
	return _instance;
}

GameEntity* GameEntityFactory::getGameEntity(eGameEntity entityEnum){

	GameEntity* newObject = new GameEntity(entityEnum);
	
	std::map<eAnimationState, Animation*>* animations;
	DrawComponent* animation = nullptr;

	switch (entityEnum){
	case Policeman:
	{
		newObject->setSpeedX(110.0f);
		//	newObject->addComponent(*new DummyComponent());

		std::vector<ComponentMessage>* healthDecreaseList = new std::vector < ComponentMessage > ; // delete called in HealthComponent
		healthDecreaseList->push_back(ComponentMessage::CollissionComponent_REACTION_TOP);

		std::vector<eGameEntity>* hurtables = new std::vector < eGameEntity > ; 
		hurtables->push_back(Player);

		newObject->addComponent(new HealthComponent(1, healthDecreaseList, hurtables));

		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new PolicemanCollisionReactionComponent());//moet nog verandert worden naar PolicemanCollisionReactionComponent
		newObject->addComponent(new gravityComponent());
		//	newObject->addComponent(new CollisionComponent());
		 animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ WalkLeft, new Animation("assets/sprites/Policeman/PolicemanWalkLeft.png", 4, 5) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Policeman/PolicemanWalkRight.png", 4, 5) });
		animation = new DrawComponent(animations);
		animation->setAnimation(WalkLeft);//set starting animation
		newObject->addComponent(animation);

		break;
	}
	case Drugdealer:
		//	newObject->addComponent(*new DummyComponent());
		break;
	case TextBox:
		newObject->addComponent(new DrawComponent("assets/sprites/TextBox.png"));
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new TextBoxInputComponent());

		break;
	case FPSCounter:
		newObject->addComponent(new FPSDrawComponent());
		break;
	case Player:
		newObject->setMovementSpeed(110.0f);
		newObject->addComponent(new PlayerInputComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new PlayerCollisionReactionComponent());
		newObject->addComponent(new gravityComponent());
		newObject->addComponent(new KnockBackComponent());
		newObject->addComponent(new HealthComponent(3));
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ IdleLeft, new Animation("assets/sprites/Ross/RossIdleLeft.png", 1) });
		animations->insert({ IdleRight, new Animation("assets/sprites/Ross/RossIdleRight.png", 1) });
		animations->insert({ WalkLeft, new Animation("assets/sprites/Ross/RossWalkingLeft.png", 8, 10) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Ross/RossWalkingRight.png", 8, 10) });
		animations->insert({ JumpLeft, new Animation("assets/sprites/Ross/RossJumpLeft.png", 1) });
		animations->insert({ JumpRight, new Animation("assets/sprites/Ross/RossJumpRight.png", 1) });

		/*
		animations->insert({ IdleLeft, new Animation("assets/sprites/Beardman/BeardmanIdleLeft.png", 1) });
		animations->insert({ IdleRight, new Animation("assets/sprites/Beardman/BeardmanIdleRight.png", 1) });
		animations->insert({ WalkLeft, new Animation("assets/sprites/Beardman/BeardmanWalkLeft.png", 8, 10) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Beardman/BeardmanWalkRight.png", 8, 10) });
		animations->insert({ JumpLeft, new Animation("assets/sprites/Beardman/BeardmanJumpLeft.png", 1) });
		animations->insert({ JumpRight, new Animation("assets/sprites/Beardman/BeardmanJumpRight.png", 1) });
		//BeardmanFallLeft
		//BeardmanFallRight
		*/

		animation = new DrawComponent(animations);
		animation->setAnimation(IdleRight);//set starting animation
		newObject->addComponent(animation);
		break;
	case Drug_Speed:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Drug_Marijuana:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_marijuana_30x30.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Drug_XTC:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_xtc_30x30.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Grass:
		//newObject->addComponent(new CollisionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/grass.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Flag:
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new FlagCollisionReactionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/Party/Flag/flag.png", 9, 10) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		newObject->addComponent(new ParticleComponent(RedLum, 0.1, 0.5));
		break;


		/* BUTTONS: */
	case ButtonPlay:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));
		newObject->addComponent(new DrawComponent("assets/buttons/button_play.jpg"));
		break;

	case ButtonPlayAgain:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));
		newObject->addComponent(new DrawComponent("assets/buttons/button_play_again.png"));
		break;
	case ButtonPlayAgainGreen:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));
		newObject->addComponent(new DrawComponent("assets/buttons/button_play_again_green.jpg"));
		break;
	case ButtonMainMenu:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelMainMenu));
		newObject->addComponent(new DrawComponent("assets/buttons/button_main_menu.png"));
		
		break;
	case ButtonMainMenuGreen:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelMainMenu));
		newObject->addComponent(new DrawComponent("assets/buttons/button_main_menu_green.jpg"));
		
		break;
	case ButtonQuitGame:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new QuitOnClickComponent());
		newObject->addComponent(new DrawComponent("assets/buttons/button_quit_game.png"));

		break;
	case ButtonQuitGameGreen:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new QuitOnClickComponent());
		newObject->addComponent(new DrawComponent("assets/buttons/button_quit_game_green.jpg"));
		break;
	case ButtonCredits:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelCredits));
		newObject->addComponent(new DrawComponent("assets/buttons/button_credits.jpg"));
		break;
	case Advertisement_GameEntity:
		newObject = new Advertisement();
		//newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new QuitOnClickComponent());
		//animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/ads/ad_1_small.png", 1) });
		//animations->insert({ Default, new Animation("assets/ads/ad_1.png", 1) });
		//animations->insert({ Default, new Animation("assets/ads/close.png", 1) });
		//animation = new DrawComponent(animations);
		//animation->setAnimation(Default);//set starting animation
		//newObject->addComponent(animation);
		break;






	default:
		throw std::invalid_argument("Invalid game Entity passed to the factory"); // Veel te lang moeten debuggen waarom mijn entities geen components hadden... >.<
	}

	return newObject;
}


GameEntityFactory::~GameEntityFactory()
{

}
