#pragma once
#include "LevelManager.h"
#include <iostream>
using std::ostream;
using std::istream;

namespace overdose {
	class SaveGame {
	public:
		SaveGame() {}
		levels savedLevelId;
		//score?
		friend ostream &operator<<(ostream &output, const SaveGame &sg)
		{
			printf("Called");
			output << sg.savedLevelId;
		}

		//friend istream &operator>>(istream  &input, SaveGame &sg)
		//{
		//	input >> sg.savedLevelId;
		//	return input;
		//}

	};
}