#include "Options.h"

using namespace overdose;
Options::Options()
{
	m_Camera = new Camera;
	m_Background = new Surface("assets/backgrounds/mainmenu.jpg");
}


Options::~Options()
{
	delete m_Background;
}

void Options::Init()
{
	GameEntity *buttonGeneral = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonGeneral);
	buttonGeneral->setPosX(50);
	buttonGeneral->setPosY(10);
	this->addEntities(buttonGeneral);

	GameEntity *buttonControls = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonControls);
	buttonControls->setPosX(50);
	buttonControls->setPosY(85);
	this->addEntities(buttonControls);

	GameEntity *ButtonDrugs = GameEntityFactory::getInstance().getGameEntity(eGameEntity::ButtonDrugs);
	ButtonDrugs->setPosX(50);
	ButtonDrugs->setPosY(160);
	this->addEntities(ButtonDrugs);

	GameEntity* button = GameEntityFactory::getInstance().getGameEntity(ButtonMainMenuGreen);
	button->setPosX(350);
	button->setPosY(400);
	addEntities(button);
}
