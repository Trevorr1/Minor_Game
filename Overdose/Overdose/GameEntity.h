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
		float posX = 1.0, posY = 1.0, speedX = 1.0, speedY = 1.0;
		float width = 0, height = 0;
		eGameEntity m_EntityEnum;
		//bool isAlive = true;
		std::vector<Component*> *compontentList = new std::vector < Component* > ;

	public:
		virtual void addComponent(Component *component);

		virtual void tick(float dt);

		void broadcast(Component *subject, ComponentMessage message, GameEntity *object);

		float getPosX();
		float getPosY();
		float getSpeedX();
		float getSpeedY();

		float getPosition(int index); // voor bsp tree

		float getWidth();
		float getHeight();
		

		eGameEntity getEnum();
		void setWidth(float width);
		void setHeight(float heigt);
		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);

		//void setCollided();

		GameEntity();
		GameEntity(eGameEntity entityEnum);

		~GameEntity();
	};


}