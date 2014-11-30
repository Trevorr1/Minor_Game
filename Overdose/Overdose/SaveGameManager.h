#pragma once
#include "SaveGame.h"
#include "stdafx.h"
#include <fstream>
#define MAX_SAVED_GAMES 5

using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

namespace overdose {
	class SaveGameManager {
	private:
		string getSaveGameName();
		bool saveGameExists(string name);
	public:
		static SaveGameManager& getInstance();
		virtual ~SaveGameManager() {}
		void save(SaveGame game);
		SaveGame load(string name);
		vector<string> getGameList();

	private:
		SaveGameManager() {}

	};

}