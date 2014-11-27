#include "HighScore.h"

using namespace overdose;
HighScore::HighScore()
{
	//Init();
}


HighScore::~HighScore()
{
	delete m_Background;
}

void HighScore::Init()
{
	m_Background = new Surface("assets/backgrounds/background.png");
}

bool HighScore::isGameOver() {
	return false;
}

