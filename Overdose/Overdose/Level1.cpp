#include "stdafx.h"
#include "Level1.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "Factory.h"

using namespace overdose;


/*Test Data*/
GameEntity* entityPtr = nullptr;
//GameEntity& entInvader = *new GameEntity();
DrawComponent* drawInvader = nullptr;

Level1::Level1()
{
	entities = new std::vector<GameEntity>();
	m_Background = new Surface("assets/backgrounds/background.jpg");
}


Level1::~Level1()
{
	delete entities;
}

void Level1::addEntities(GameEntity* entities)
{
	this->entities->push_back(*entities);
}

void Level1::Init()
{



	/*Test Data*/
	entityPtr = Factory::getInstance()->getGameEntity(eGameEntity::DrugAddict);

	entityPtr->setSpeedY(0);

	this->addEntities(entityPtr);
}
void Level1::Tick(float dt){


	/*Test Data*/
}

void Level1::Render(Surface* surface){
	m_Background->CopyTo(surface, 0, 0);

	entityPtr->tick();
	
	/*TODO: Right now, the tick method will be called first, 
					   then the Render. Units with the draw component will be rendered first, 
					   and thus wont be visible because the background is in front of them*/

}

GameEntity* Level1::getPlayerEntity(){
	return m_Player;
}

std::vector<GameEntity>* Level1::getEntities(){
	return entities;
}
