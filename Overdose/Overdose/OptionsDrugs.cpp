#include "OptionsDrugs.h"
#include "TextGameEntity.h"
using namespace overdose;
OptionsDrugs::OptionsDrugs()
{
	m_Camera = new Camera;
	m_Background = new Surface("assets/backgrounds/empty.jpg");
}


OptionsDrugs::~OptionsDrugs()
{
	delete m_Background;
}

void OptionsDrugs::Init()
{
	TextGameEntity* text = new TextGameEntity("marijuana");

	text->setPosX(20);
	text->setPosY(10);
	text->setHeight(10);
	addEntities(text);

	GameEntity* marijuana = GameEntityFactory::getInstance().getGameEntity(OptionsMarijuana);
	marijuana->setPosX(50);
	marijuana->setPosY(50);
	addEntities(marijuana);

	text = new TextGameEntity("postive effect");

	text->setPosX(85);
	text->setPosY(30);
	text->setHeight(10);
	addEntities(text);

	text = new TextGameEntity("world moves in slowmotion targets are now easier to hit");

	text->setPosX(85);
	text->setPosY(50);
	text->setHeight(10);
	addEntities(text);

	text = new TextGameEntity("negative effect");

	text->setPosX(85);
	text->setPosY(75);
	text->setHeight(10);
	addEntities(text);

	text = new TextGameEntity("world changes color");

	text->setPosX(85);
	text->setPosY(95);
	text->setHeight(10);
	addEntities(text);


	//Speed
	text = new TextGameEntity("speed");

	text->setPosX(20);
	text->setPosY(130);
	addEntities(text);

	GameEntity* speed = GameEntityFactory::getInstance().getGameEntity(OptionsSpeed);
	speed->setPosX(50);
	speed->setPosY(170);
	addEntities(speed);

	text = new TextGameEntity("positive effect");

	text->setPosX(85);
	text->setPosY(150);
	addEntities(text);

	text = new TextGameEntity("you move faster for a while");

	text->setPosX(85);
	text->setPosY(170);
	addEntities(text);

	text = new TextGameEntity("negative effect");

	text->setPosX(85);
	text->setPosY(195);
	addEntities(text);

	text = new TextGameEntity("you move slower for a while");

	text->setPosX(85);
	text->setPosY(215);
	addEntities(text);

	//XTC
	text = new TextGameEntity("xtc");

	text->setPosX(20);
	text->setPosY(240);
	addEntities(text);

	GameEntity* xtc = GameEntityFactory::getInstance().getGameEntity(OptionsXTC);
	xtc->setPosX(50);
	xtc->setPosY(280);
	addEntities(xtc);

	text = new TextGameEntity("positive effect");

	text->setPosX(85);
	text->setPosY(260);
	addEntities(text);

	text = new TextGameEntity("you become invulnerable for a while");

	text->setPosX(85);
	text->setPosY(280);
	addEntities(text);

	text = new TextGameEntity("negative effect");

	text->setPosX(85);
	text->setPosY(305);
	addEntities(text);

	text = new TextGameEntity("the controls become inverted");

	text->setPosX(85);
	text->setPosY(325);
	addEntities(text);

	GameEntity* button = GameEntityFactory::getInstance().getGameEntity(ButtonOptionsBack);
	button->setPosX(350);
	button->setPosY(400);
	addEntities(button);
}