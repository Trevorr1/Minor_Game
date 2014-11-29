#include "stdafx.h"
#include "ScoreManager.h"


ScoreManager::ScoreManager()
{
	std::cout << "Succesfully initialised ScoreManager" << std::endl;
}


ScoreManager::~ScoreManager()
{
}

ScoreManager &ScoreManager::getInstance()
{
	static ScoreManager _instance;
	return _instance;
}