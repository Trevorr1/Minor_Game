#pragma once
#include "Ilevel.h"
namespace overdose {
	class HighScore : public ILevel
	{
	public:
		HighScore();
		virtual ~HighScore();
		void Init();
		bool isGameOver();
	private:
		void getHighScoreList();
	};
}
