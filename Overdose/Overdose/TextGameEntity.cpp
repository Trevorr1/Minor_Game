#include "TextGameEntity.h"
#include "DrawManager.h"
using namespace overdose;

TextGameEntity::TextGameEntity(char* contents) {
	m_EntityEnum = Text;
	m_Text = contents;
}

void TextGameEntity::tick(float dt) {
	GameEntity::tick(dt);

	DrawManager::getInstance().getLevelSurface()->WriteText(m_Text, getPosX(), getPosY());
}