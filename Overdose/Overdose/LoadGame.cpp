#include "LoadGame.h"
#include "SaveGameManager.h"
#include "TextGameEntity.h"
#include "MouseOverEffectComponent.h"
#include "ButtonClickableReactionComponent.h"
#include "ClickableComponent.h"
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
	int posY = 40;

	TextGameEntity *mainText = new TextGameEntity("please select a saved game below");
	mainText->setPosY(10);
	mainText->setPosX(300);
	addEntities(mainText);
	for (string name : gameList) {

		string prefix = "Savegame";
	///	prefix.append(name);
		//char* content = const_cast<char*>(prefix.c_str());
		
		TextGameEntity* text = new TextGameEntity("save game");

		SaveGame game = SaveGameManager::getInstance().load(name);

		text->addComponent(new MouseOverEffectComponent);
		text->addComponent(new ClickableComponent);
		text->addComponent(new ButtonClickableReactionComponent(game.savedLevelId));

		text->setPosX(400);
		text->setPosY(posY);
		text->setHeight(15);
		text->setWidth(100); // nodig voor MouseOverComponet
		posY += 40;
		addEntities(text);
	}
}