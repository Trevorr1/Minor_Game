#include "ScoreboardManager.h"

using namespace overdose;
ScoreboardManager::ScoreboardManager()
{
	std::cout << "Initialized score manager" << std::endl;
}


ScoreboardManager::~ScoreboardManager()
{
}

ScoreboardManager &ScoreboardManager::getInstance()
{
	static ScoreboardManager _instance;
	return _instance;
}

float ScoreboardManager::getScore()
{
	return m_score;
}

std::string ScoreboardManager::getName()
{
	return m_curname;
}

void ScoreboardManager::setName(std::string name)
{
	m_curname = name;
}

void ScoreboardManager::startTimer()
{
	timer = (m_score * 1000) + std::clock(); //convert seconds to ms, so our clock wont start at zero when loading a new level
}

void ScoreboardManager::stopTimer()
{
	clock_t endc = std::clock();
	float score = endc - timer;
	setScore((score/ 1000)); //ms to seconds
}

void ScoreboardManager::resetTimer()
{
	m_score = 0;
}

void ScoreboardManager::setScore(float score) //score in seconds
{
	m_score = score; 
}

void ScoreboardManager::persistScore(std::string name, float score) //score in seconds
{
	//read text file
	//make map from the scores
	std::multimap<float, std::string > scoreList = getScoreList();
	//order the map with the new score
	scoreList.insert(make_pair(score, name));

	//convert multimap to sorted set
	std::multiset<std::pair<float, std::string>> scoreSet;
	for (std::multimap<float, std::string>::iterator i = scoreList.begin(); i != scoreList.end(); i++)
		scoreSet.insert(std::pair<float, std::string>((*i).first, (*i).second));
	
	//save text file

	std::ofstream m_file(m_url);
	if (m_file.is_open())
	{
		for (auto it = scoreSet.begin(); it != scoreSet.end(); it++)
		{
			m_file << std::to_string(it->first) << ";" << it->second << std::endl;
		}
		m_file.close();
	}
}

std::multimap<float, std::string > ScoreboardManager::getScoreList()
{
	std::multimap<float, std::string > scoreList;
	std::fstream m_file (m_url, std::fstream::in | std::fstream::out);
	std::string line;
	while (std::getline(m_file, line))
	{
		std::vector<std::string> tmpMap = split(line, ";");
		std::string playerName = tmpMap.at(1);
		float score = ::atof(tmpMap.at(0).c_str());
		scoreList.insert(make_pair(score, playerName));
	}

	return scoreList;
}

std::vector<std::string> ScoreboardManager::split(std::string s, std::string delimiter)
{
	std::vector<std::string> tempMap;

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		tempMap.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	tempMap.push_back(s);
	return tempMap;
}