#pragma once
#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <set>
#include <fstream>

namespace overdose {
	class ScoreboardManager
	{
	public:
		virtual ~ScoreboardManager();
		static ScoreboardManager &getInstance();

		void startTimer();
		void stopTimer();
		void resetTimer();

		float getScore();
		void setScore(float score);

		//put score and playername in a textfile
		void persistScore(std::string playerName, float m_score);
		std::multimap<float, std::string > getScoreList();
	private:
		ScoreboardManager();
		static ScoreboardManager* _instance;
		float m_score;
		bool reset = false;
		time_t timer = 0;
		std::string m_url = "score.txt";
		std::vector<std::string> split(std::string s, std::string delimiter);
	};
}