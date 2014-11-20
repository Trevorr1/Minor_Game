#include "Advertisement.h"

using namespace overdose;

Advertisement::Advertisement()
{
	timer_start = NULL;
	timer_ms = 1000 * 5;
}

Advertisement::~Advertisement()
{	
	std::cout << "Deleted Advertisement " << std::endl;
}

void Advertisement::tick(float dt){
	if (timer_start == NULL){
		timer_start = std::clock();
	}
	int timer_end = (int)((std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000));

	// timer checker
	if (timer_end < timer_ms){
		std::cout << timer_end << std::endl;
	}

	for (auto &it : *componentList) {
		it->tick(dt, this);
	}
}
