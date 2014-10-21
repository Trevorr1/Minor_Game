#include "stdafx.h"
#include "GameOver.h"
#include "PlayerInputComponent.h"
/*Test Data*/
#include "DrawComponent.h"
#include "MoveComponent.h"
#include "GameEntityFactory.h"
#include "SoundManager.h"

using namespace overdose;



GameOver::GameOver()
{
	entities = new std::vector<GameEntity*>();
	enemies = new std::vector<GameEntity*>();
	collectibles = new std::vector<GameEntity*>();
	m_Background = new Surface("assets/backgrounds/gameover.jpg");
}


GameOver::~GameOver()
{
	delete entities;
	delete collectibles;
	delete m_Background;
	delete enemies;
}

void GameOver::Init()
{

	SoundManager::getInstance()->StopMusic();
	SoundManager::getInstance()->PlaySound(eSound::GameOverSound);
}

bool GameOver::isGameOver() {
	return false;
}