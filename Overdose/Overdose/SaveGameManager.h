#pragma once
#include "SaveGame.h"
#include "stdafx.h"
#include <fstream>
#define MAX_SAVED_GAMES 3

using std::string;
using std::ofstream;
namespace overdose {
	class SaveGameManager {
	private:
		string getSaveGameName();
		bool saveGameExists(string name);
	public:
		static SaveGameManager& getInstance();
		virtual ~SaveGameManager() {}
		void save(SaveGame* game);

	private:
		SaveGameManager() {}

	};

}