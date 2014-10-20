#pragma once
#include "stdafx.h"
#include "Enum.h"
#include "Component.h"
#include "ComponentMessage.h" 

namespace overdose {
	class Component;
	class GameEntity
	{
	protected:
		float posX = 0.0, posY = 0.0, speedX = 0.0, speedY = 0.0;
		float m_movementSpeed = 0.0f;
		float width = 0, height = 0;
		eGameEntity m_EntityEnum;
		bool m_scheduledForRemoval = false;

		std::vector <int> *componentListToRemove = new std::vector < int >;
		std::vector<Component*> *componentList = new std::vector < Component* > ;

	public:
		virtual void addComponent(Component *component);

		virtual void tick(float dt);

		virtual std::vector<Component*>* getComponentList();

		void broadcast(Component *subject, ComponentMessage message, GameEntity *object);

		virtual void removeComponent(std::string componentString);

		void scheduleForRemoval();
		bool isScheduledForRemoval();

		float getWidth();
		float getHeight();
		float getSpeedX();
		float getSpeedY();
		float getPosX();
		float getPosY();
		float getMovementSpeed();

		float getPosition(int index); // voor bsp tree

		

		eGameEntity getEnum();
		void setWidth(float width);
		void setHeight(float heigt);
		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);
		void setMovementSpeed(float movementspeed);

		//void setCollided();

		GameEntity();
		GameEntity(eGameEntity entityEnum);

		~GameEntity();
	};


}