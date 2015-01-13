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
#include "DeleteEntityClickComponent.h"
#include "URLClickComponent.h"
#include "MouseOverEffectComponent.h"
#include "FocusPointerComponent.h"
#include "TutorialClickableComponent.h"
#include "ScoreboardManager.h"
#include "AIComponent.h"
#include "DisplayHealthComponent.h"
#include "DrugOscillationComponent.h"
#include "DrugDropComponent.h"
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
	//	newObject->addComponent(new gravityComponent());
		 animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ WalkLeft, new Animation("assets/sprites/Policeman/PolicemanWalkLeft.png", 4, 5) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Policeman/PolicemanWalkRight.png", 4, 5) });
		animation = new DrawComponent(animations);
		animation->setAnimation(WalkLeft);//set starting animation
		newObject->addComponent(animation);
		break;
	}
	case Urquhart: 
	{
		newObject->setSpeedX(110.0f);
		std::vector<ComponentMessage>* healthDecreaseList = new std::vector < ComponentMessage >; // delete called in HealthComponent
		healthDecreaseList->push_back(ComponentMessage::CollissionComponent_REACTION_TOP);
		std::vector<eGameEntity>* hurtables = new std::vector < eGameEntity >;
		hurtables->push_back(Player);

		newObject->addComponent(new HealthComponent(5, healthDecreaseList, hurtables));
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new AIComponent());
		newObject->addComponent(new DisplayHealthComponent());
		newObject->addComponent(new DrugDropComponent);
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ WalkLeft, new Animation("assets/sprites/Urquhart/UrquhartWalkLeft.png", 4, 5) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Urquhart/UrquhartWalkRight.png", 4, 5) });
		animations->insert({ Default, new Animation("assets/sprites/Urquhart/UrquhartFlyAttack.png", 1, 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(WalkLeft);//set starting animation
		newObject->addComponent(animation);



	}
	case Drugdealer:
		//	newObject->addComponent(*new DummyComponent());
		break;
	case TextBox:
		newObject->addComponent(new DrawComponent("assets/sprites/TextBox.png"));
		newObject->addComponent(new TextBoxInputComponent());

		break;
	case FPSCounter:
		newObject->addComponent(new FPSDrawComponent());
		break;
	case Player:
		newObject->setMovementSpeed(190.0f);
		newObject->addComponent(new PlayerInputComponent());
		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new PlayerCollisionReactionComponent());
		newObject->addComponent(new gravityComponent());
		newObject->addComponent(new KnockBackComponent());
		newObject->addComponent(new HealthComponent(3));
		//newObject->addComponent(new ParticleComponent(Blood, 0.01, 0.5, 0.5));
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
		newObject->addComponent(new DrugOscillationComponent());
		break;
	case Drug_Marijuana:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_marijuana_30x30-2.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		newObject->addComponent(new DrugOscillationComponent());
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
		newObject->addComponent(new DrugOscillationComponent());
		break;
	case Grass:
		//newObject->addComponent(new CollisionComponent());
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/grass_2.png", 1) });
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
		newObject->addComponent(new ParticleComponent(RedLum, 0.1, 0.5, 0.1));
		break;
	case Ground:
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/ground.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		newObject->setEnum(eGameEntity::Grass); //ricardo hack
		break;

	case Bullet:
	{
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/bullet.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		newObject->addComponent(new MoveComponent);
		newObject->addComponent(new KillSwitchComponent(3));



		break;
	}

		/* BUTTONS: */
	case ButtonPlay:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));
		newObject->addComponent(new DrawComponent("assets/buttons/button_play1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;

	case ButtonPlayAgain:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));
		newObject->addComponent(new DrawComponent("assets/buttons/button_play_again.png"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonPlayAgainGreen:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(level1));
		newObject->addComponent(new DrawComponent("assets/buttons/button_play_again_green1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonMainMenu:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelMainMenu));
		newObject->addComponent(new DrawComponent("assets/buttons/button_main_menu.png"));
		newObject->addComponent(new MouseOverEffectComponent);

		break;
	case ButtonMainMenuGreen:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelMainMenu));
		newObject->addComponent(new DrawComponent("assets/buttons/button_main_menu_green1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);

		break;
	case ButtonQuitGame:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new QuitOnClickComponent());
		newObject->addComponent(new DrawComponent("assets/buttons/button_quit_game.png"));
		newObject->addComponent(new MouseOverEffectComponent);

		break;
	case ButtonQuitGameGreen:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new QuitOnClickComponent());
		newObject->addComponent(new DrawComponent("assets/buttons/button_quit_game_green1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonCredits:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelCredits));
		newObject->addComponent(new DrawComponent("assets/buttons/button_credits1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonLoadGame:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelLoadGame));
		newObject->addComponent(new DrawComponent("assets/buttons/button_load_game1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonHighScore:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelHighScore));
		newObject->addComponent(new DrawComponent("assets/buttons/button_highscore1.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonOptions:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelOptions));
		newObject->addComponent(new DrawComponent("assets/buttons/button_options.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonGeneral:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelOptionsGeneral));
		newObject->addComponent(new DrawComponent("assets/buttons/button_options_general.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonControls:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelOptionsControls));
		newObject->addComponent(new DrawComponent("assets/buttons/button_options_controls.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonDrugs:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelOptionsDrugs));
		newObject->addComponent(new DrawComponent("assets/buttons/button_options_drugs.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	case ButtonOptionsBack:
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new ButtonClickableReactionComponent(LevelOptions));
		newObject->addComponent(new DrawComponent("assets/buttons/button_options_back.jpg"));
		newObject->addComponent(new MouseOverEffectComponent);
		break;
	//Drugs for options menu
	case OptionsMarijuana:
		newObject->addComponent(new DrawComponent("assets/sprites/drug_marijuana_30x30-2.png"));
		break;
	case OptionsSpeed:
		newObject->addComponent(new DrawComponent("assets/sprites/drug_speed_30x30.png"));
		break;
	case OptionsXTC:
		newObject->addComponent(new DrawComponent("assets/sprites/drug_xtc_30x30.png"));
		break;
	case OptionsArrowRight:
		newObject->addComponent(new DrawComponent("assets/misc/arrow_right.jpg"));
		break;
	case OptionsArrowLeft:
		newObject->addComponent(new DrawComponent("assets/misc/arrow_left.jpg"));
		break;
	case OptionsSpacebar:
		newObject->addComponent(new DrawComponent("assets/misc/spacebar.jpg"));
		break;

	case Advertisement_GameEntity:
	{
		//Advertisement classe gaat fout, door de inheritance?
		//GameEntity* closeButton = new GameEntity();
		//std::map<eAnimationState, Animation*>* animations2;
		//animations2 = new std::map<eAnimationState, Animation*>();
		//animations2->insert({ Default, new Animation("assets/ads/close.png", 1) });
		////DrawComponent* animation2 = new DrawComponent(animations2, animation);
		//DrawComponent* animation2 = new DrawComponent(animations2);
		//animation2->setAnimation(Default);//set starting animation
		//closeButton->addComponent(animation2);
		//closeButton->addComponent(new ClickableComponent());
		//closeButton->addComponent(new DeleteEntityClickComponent());

		//delete newObject;
		//Advertisement* newObject = new Advertisement(entityEnum, closeButton);
		newObject->addComponent(new KillSwitchComponent(4));// alternative for Advertisement
		newObject->addComponent(new ClickableComponent());
		newObject->addComponent(new URLClickComponent("https://www.google.nl/webhp?sourceid=chrome-instant&ion=1&espv=2&ie=UTF-8#q=klm"));
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/ads/ad_1_small.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);

		break;
	}

	/* Tutorial entities */
	case Tutorial_Explanation:
		newObject->addComponent(new TutorialClickableComponent());
		//newObject->addComponent(new MoveComponent());
		//newObject->addComponent(new CollisionComponent());
		//newObject->addComponent(new DrugCollisionReactionComponent());
		//newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_sprite.png", 3, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Level1:
	{
		GameEntity* tut_Goal = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_Goal);
		tut_Goal->addComponent(new TutorialClickableComponent());
		GameEntity* tut_HUD = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_HUD);
		tut_HUD->addComponent(new TutorialClickableComponent(tut_Goal));
		GameEntity* tut_Spacebar = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_Spacebar);
		tut_Spacebar->addComponent(new TutorialClickableComponent(tut_HUD));
		newObject->addComponent(new TutorialClickableComponent(tut_Spacebar));
		//newObject->addComponent(new MoveComponent());
		//newObject->addComponent(new CollisionComponent());
		//newObject->addComponent(new DrugCollisionReactionComponent());
		//newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_arrow_keys.png", 1, 0) }); //first tut image
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	}
	case Tutorial_Arrow_Keys:
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_arrow_keys.png", 1, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Spacebar:
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_spacebar.png", 1, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Goal:
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_goal.png", 1, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_HUD:
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_hud.png", 1, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Level2:
	{
		newObject->addComponent(new TutorialClickableComponent());
		//newObject->addComponent(new MoveComponent());
		//newObject->addComponent(new CollisionComponent());
		//newObject->addComponent(new DrugCollisionReactionComponent());
		//newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_respawn.png", 1, 0) }); // first tut image
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	}
	case Tutorial_Level3:
	{
		GameEntity* tut_Cop = GameEntityFactory::getInstance().getGameEntity(eGameEntity::Tutorial_Cop);
		tut_Cop->addComponent(new TutorialClickableComponent());
		newObject->addComponent(new TutorialClickableComponent(tut_Cop));
		//newObject->addComponent(new MoveComponent());
		//newObject->addComponent(new CollisionComponent());
		//newObject->addComponent(new DrugCollisionReactionComponent());
		//newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_drug_speed.png", 1, 0) }); //first tut image
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	}
	case Tutorial_SpeedDrug:
		newObject->addComponent(new TutorialClickableComponent());
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_drug_speed196x196.png", 1, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Cop:
		newObject->addComponent(new TutorialClickableComponent());
		animations = new std::map<eAnimationState, Animation*>();
		//animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animations->insert({ Default, new Animation("assets/tutorial/tutorial_cop196x196.png", 1, 0) });
		//animation = new TutorialDrawComponent(animations);
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Policeman:
	{
		newObject->setSpeedX(110.0f);
		//	newObject->addComponent(*new DummyComponent());

		std::vector<ComponentMessage>* healthDecreaseList = new std::vector < ComponentMessage >; // delete called in HealthComponent
		healthDecreaseList->push_back(ComponentMessage::CollissionComponent_REACTION_TOP);

		std::vector<eGameEntity>* hurtables = new std::vector < eGameEntity >;
		hurtables->push_back(Player);

		newObject->addComponent(new HealthComponent(1, healthDecreaseList, hurtables));

		newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new PolicemanCollisionReactionComponent());//moet nog verandert worden naar PolicemanCollisionReactionComponent
		newObject->addComponent(new gravityComponent());
		newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::RED)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ WalkLeft, new Animation("assets/sprites/Policeman/PolicemanWalkLeft.png", 4, 5) });
		animations->insert({ WalkRight, new Animation("assets/sprites/Policeman/PolicemanWalkRight.png", 4, 5) });
		animation = new DrawComponent(animations);
		animation->setAnimation(WalkLeft);//set starting animation
		newObject->addComponent(animation);
		break;
	}
	case Tutorial_Drug_Speed:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_speed_30x30.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Drug_Marijuana:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_marijuana_30x30-2.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;
	case Tutorial_Drug_XTC:
		newObject->addComponent(new ClickableComponent());
		//newObject->addComponent(new MoveComponent());
		newObject->addComponent(new CollisionComponent());
		newObject->addComponent(new DrugCollisionReactionComponent());
		newObject->addComponent(new FocusPointerComponent(newObject, FocusPointerComponent::YELLOW)); //only way to add this component
		animations = new std::map<eAnimationState, Animation*>();
		animations->insert({ Default, new Animation("assets/sprites/drug_xtc_30x30.png", 1) });
		animation = new DrawComponent(animations);
		animation->setAnimation(Default);//set starting animation
		newObject->addComponent(animation);
		break;

	default:
		throw std::invalid_argument("Invalid game Entity passed to the factory"); // Veel te lang moeten debuggen waarom mijn entities geen components hadden... >.<
	}

	return newObject;
}


GameEntityFactory::~GameEntityFactory()
{

}
