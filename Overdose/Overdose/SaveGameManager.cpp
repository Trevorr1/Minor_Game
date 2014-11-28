#include "SaveGameManager.h"
using namespace overdose;

SaveGameManager &SaveGameManager::getInstance()
{
	static SaveGameManager _instance;
	return _instance;
}

void SaveGameManager::save(SaveGame* game) {
	const string path("assets/savegames/" + getSaveGameName() + ".txt");
	ofstream output_file(path);

	output_file << game->savedLevelId << std::endl;
	delete game;
}

bool SaveGameManager::saveGameExists(string name) {
	string path = "assets/savegames/";
	path.append(name);
	path.append(".txt");
    std::ifstream infile(path);
    return infile.good();
}

string SaveGameManager::getSaveGameName() {

	int name = 1;

	while (saveGameExists(std::to_string(name))) {
		++name;
	}

	return std::to_string(name);
}