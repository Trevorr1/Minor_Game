#include "HighScore.h"
#include "TextGameEntity.h"
#include "ScoreboardManager.h"
#include "GameEntityFactory.h"

using namespace overdose;
HighScore::HighScore()
{
	m_Camera = new Camera;
	m_Background = new Surface("assets/backgrounds/empty.jpg");
}


HighScore::~HighScore()
{
	delete m_Background;
	for (int i = 0; i < toDelete.size(); i++)
	{
		free(toDelete.at(i));
	}
}

void HighScore::Init()
{
	TextGameEntity *mainText = new TextGameEntity("highscore");
	mainText->setPosY(10);
	mainText->setPosX(275);
	addEntities(mainText);

	int posY = 10;

	std::multimap<float, std::string> list = ScoreboardManager::getInstance().getScoreList();
	int i = 0;
	float score;

	std::string player_name;

	if (list.size() == 0)
	{
		TextGameEntity* text = new TextGameEntity("no scores yet to display");

		text->setPosX(400);
		text->setPosY(posY);
		text->setHeight(15);
		posY += 40;
		addEntities(text);
	}

	for (std::multimap<float, std::string>::iterator itr = list.begin(); itr != list.end(); ++itr)
	{
		if (i > 10)
		{
			return;
		}

		score = itr->first;
		player_name = itr->second;
		i++;

		std::transform(player_name.begin(), player_name.end(), player_name.begin(), ::tolower);

		std::string to_char = std::to_string(i) + " " + player_name + " " + std::to_string(int(score)) + " seconds ";
		char *highscore = _strdup(to_char.c_str()); //convert to char //changed strdup to _strdup Ricardo

		TextGameEntity* text = new TextGameEntity(highscore);

		text->setPosX(400);
		text->setPosY(posY);
		text->setHeight(15);
		posY += 40;
		addEntities(text);

		toDelete.push_back(highscore);
	}


	GameEntity* button = GameEntityFactory::getInstance().getGameEntity(ButtonMainMenuGreen);
	button->setPosX(320);
	button->setPosY(380);
	addEntities(button);
}

bool HighScore::isGameOver() {
	return false;
}

