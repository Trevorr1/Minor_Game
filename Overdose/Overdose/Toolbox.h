#pragma once
#include <vector>

namespace overdose {
	template<typename T>
	void clearList(std::vector<T*>* list){
		while (!list->empty()) {
			delete list->back();
			list->pop_back();
		}

		delete list;

	}
}