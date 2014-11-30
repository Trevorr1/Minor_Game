#include "SaveGameManager.h"
#include "directory.h"
using namespace overdose;

SaveGameManager &SaveGameManager::getInstance()
{
	static SaveGameManager _instance;
	return _instance;
}

void SaveGameManager::save(SaveGame game) {
	const string path("assets/savegames/" + getSaveGameName());
	ofstream output_file(path);

	output_file << game.savedLevelId << std::endl;


}

SaveGame SaveGameManager::load(string name) {
	const string path("assets/savegames/" + name);

	SaveGame game;
	ifstream input_file(path);

	int level;
	input_file >> level;

	game.savedLevelId = levels(level);
	return game;
}

bool SaveGameManager::saveGameExists(string name) {
	string path = "assets/savegames/";
	path.append(name);
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

vector<string> SaveGameManager::getGameList() {
	vector<string> list = read_directory("assets/savegames");
	vector<string> returnList;

	vector<string>::reverse_iterator it = list.rbegin();


	while (it != list.rend()) {
		
		if (*it != "." && *it != "..") { // dir up & dir down
			returnList.push_back(*it);
		}
		

		it++;

	}
	
	return returnList;
}