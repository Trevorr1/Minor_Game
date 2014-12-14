#include "OptionsControls.h"
#include "TextGameEntity.h"
using namespace overdose;
OptionsControls::OptionsControls()
{
	m_Camera = new Camera;
	m_Background = new Surface("assets/backgrounds/mainmenu.jpg");
}


OptionsControls::~OptionsControls()
{
	delete m_Background;
}

void OptionsControls::Init()
{
	TextGameEntity* text = new TextGameEntity("default controls");

	text->setPosX(20);
	text->setPosY(10);
	text->setHeight(10);
	addEntities(text);

	GameEntity* left = GameEntityFactory::getInstance().getGameEntity(OptionsArrowLeft);
	left->setPosX(100);
	left->setPosY(100);
	addEntities(left);

	text = new TextGameEntity("move left");

	text->setPosX(70);
	text->setPosY(160);
	text->setHeight(10);
	addEntities(text);

	GameEntity* right = GameEntityFactory::getInstance().getGameEntity(OptionsArrowRight);
	right->setPosX(250);
	right->setPosY(100);
	addEntities(right);

	text = new TextGameEntity("move right");

	text->setPosX(220);
	text->setPosY(160);
	text->setHeight(10);
	addEntities(text);

	GameEntity* spacebar = GameEntityFactory::getInstance().getGameEntity(OptionsSpacebar);
	spacebar->setPosX(145);
	spacebar->setPosY(200);
	addEntities(spacebar);

	text = new TextGameEntity("jump");

	text->setPosX(180);
	text->setPosY(260);
	text->setHeight(10);
	addEntities(text);

	GameEntity* button = GameEntityFactory::getInstance().getGameEntity(ButtonOptionsBack);
	button->setPosX(350);
	button->setPosY(400);
	addEntities(button);
}