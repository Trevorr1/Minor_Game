#include "LoadGame.h"
#include "SaveGameManager.h"
#include "TextGameEntity.h"
#include "MouseOverEffectComponent.h"
using namespace overdose;

LoadGame::LoadGame() {
	m_Camera = new Camera;
	m_Background = new Surface("assets/backgrounds/empty.jpg");
}

LoadGame::~LoadGame() {
	delete m_Background;
}


void LoadGame::Init() {
	vector<string> gameList = SaveGameManager::getInstance().getGameList();
	int posY = 10;
	for (string name : gameList) {
		string prefix = "Savegame #";
		prefix.append(name);
		char* content = const_cast<char*>(prefix.c_str());
		TextGameEntity* text = new TextGameEntity(content);
		text->addComponent(new MouseOverEffectComponent);
		text->setPosX(400);
		text->setPosY(posY);
		text->setHeight(15);
		text->setWidth(15); // nodig voor MouseOverComponet
		posY += 40;
		addEntities(text);
	}
}