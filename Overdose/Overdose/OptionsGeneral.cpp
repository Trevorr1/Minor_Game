#include "OptionsGeneral.h"
using namespace overdose;
OptionsGeneral::OptionsGeneral()
{
	m_Camera = new Camera;
	m_Background = new Surface("assets/backgrounds/mainmenu.jpg");
}


OptionsGeneral::~OptionsGeneral()
{
	delete m_Background;
}

void OptionsGeneral::Init()
{
	GameEntity* button = GameEntityFactory::getInstance().getGameEntity(ButtonOptionsBack);
	button->setPosX(350);
	button->setPosY(400);
	addEntities(button);
}