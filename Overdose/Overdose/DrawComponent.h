#pragma once
#include "Component.h"
#include "surface.h"
#include "AnimationEnum.h"
#include "Animation.h"	
#include <map>

namespace overdose {
	
	class DrawComponent : public Component
	{
	public:

		DrawComponent(std::map<eAnimationState, Animation*>* animations);
		virtual ~DrawComponent();

		void init(GameEntity *entity);
		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void receiveMessageBatch(Component *subject, std::map<ComponentMessage, GameEntity*> messages);
		void tick(float dt, GameEntity *entity);
		std::string getComponentID();

		void setAnimation(eAnimationState state);

	private:
		Sprite* m_SpriteSheet;
		void NextSprite();
		unsigned int m_FPS = 0;
		float m_timePerFrame = 0.0f;
		float m_currentDTcount = 0.0f;

		std::map<eAnimationState, Animation*>* m_Animations;
		void setCurrentAnimation(Animation* animation);

	};
}
