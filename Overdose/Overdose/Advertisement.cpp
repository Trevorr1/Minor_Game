#include "Advertisement.h"
#include "AnimationEnum.h"
#include "Animation.h"
#include "DrawComponent.h"
#include "ClickableComponent.h"
#include "QuitOnClickComponent.h"
using namespace overdose;

Advertisement::Advertisement()
{
	timer_start = NULL;
	timer_ms = 1000 * 5;

	std::map<eAnimationState, Animation*>* animations;
	animations = new std::map<eAnimationState, Animation*>();
	animations->insert({ Default, new Animation("assets/ads/ad_1_small.png", 1) });
	DrawComponent* animation = new DrawComponent(animations);
	animation->setAnimation(Default);//set starting animation
	this->addComponent(animation);

	std::map<eAnimationState, Animation*>* animations2;
	animations2 = new std::map<eAnimationState, Animation*>();
	animations2->insert({ Default, new Animation("assets/ads/close.png", 1) });
	DrawComponent* animation2 = new DrawComponent(animations2, animation);
	animation2->setAnimation(Default);//set starting animation
	this->addComponent(animation2);
	this->addComponent(new ClickableComponent());
	this->addComponent(new QuitOnClickComponent()); // adClickComponent maken en die linkt naar website

	// set to nullptr nodig?
	animations = nullptr;
	animation = nullptr;
	animations2 = nullptr;
	animation2 = nullptr;
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
