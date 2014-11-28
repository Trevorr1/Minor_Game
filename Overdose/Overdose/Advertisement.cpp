#include "Advertisement.h"

using namespace overdose;

Advertisement::Advertisement()
{
	timer_start = NULL;
	timer_ms = 1000 * 5;
	init();
}

Advertisement::Advertisement(eGameEntity entityEnum, GameEntity* closeButton){
	m_EntityEnum = entityEnum;
	this->closeButton = closeButton;
	init();
}

void Advertisement::init(){
	timer_start = NULL;
	timer_ms = 1000 * 5;
}

Advertisement::~Advertisement()
{	
	if ( closeButton != nullptr){
		delete closeButton;
		closeButton = nullptr;
	}
	std::cout << "Deleted Advertisement " << std::endl;
 }

void Advertisement::tick(float dt){
	if (timer_start == NULL){
		timer_start = std::clock();
	}
	int timer_end = (int)((std::clock() - timer_start) / (double)(CLOCKS_PER_SEC / 1000));

	// timer checker
	if (timer_end < timer_ms){
		//std::cout << timer_end << std::endl;
	}
	else {
		this->scheduleForRemoval();
	}

	for (auto &it : *componentList) {
		it->tick(dt, this);
	}
	
	//Close button
	if (closeButton != nullptr){
		//Close button tick
		if (closeButton->isScheduledForRemoval() == false){
			closeButton->tick(dt);
		}
		//Close button isScheduledForRemoval() == true, scheduleForRemoval this Advertisement
		else{
			this->scheduleForRemoval();
		}
	}
}

void Advertisement::setStartingPosition(float x, float y){
	posX = startPosX = x;
	posY = startPosY = y;

	if (closeButton != nullptr){
		closeButton->setPosX(this->getWidth() + this->getStartPosX() - closeButton->getWidth());
		closeButton->setPosY(y - closeButton->getHeight());//closeButton->setPosY(y);
	}
}


