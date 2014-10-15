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
		float width = 0, height = 0;
		eGameEntity m_EntityEnum;
		std::vector<Component*> *componentList = new std::vector < Component* > ;

		// for collision :<
		bool isAlive = true, collidedTop = false, collidedBottom = false, collidedLeft = false,
			collidedRight = false, reactTop = false, reactBottom = false, reactLeft = false, reactRight = false;
		int colX = 0, colY = 0, colBoxX = 0, colBoxY = 0;


	public:
		virtual void addComponent(Component *component);

		virtual void tick(float dt);

		virtual std::vector<Component*>* getComponentList();

		void broadcast(Component *subject, ComponentMessage message, GameEntity *object);

		virtual void removeComponent(std::string componentString);

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

		/*	All of this shit is for collision
		*	it is ugly filthy shit code that I HATE!!
		*	but it will work and that's what we need right now :@
		*/
		void setFlag(ComponentMessage message, GameEntity *other);

		int getColX();
		int getColY();
		int getColBoxX();
		int getColBoxY();

		bool getAlive();
		bool getCollideTop();
		bool getCollideBottom();
		bool getCollideLeft();
		bool getCollideRight();

		bool getReactTop();
		bool getReactBottom();
		bool getReactLeft();
		bool getReactRight();

		void setCollideTop(bool ctop);
		void setCollideBottom(bool cbot);
		void setCollideLeft(bool cleft);
		void setCollideRight(bool cright);

		void setReactTop(bool rtop);
		void setReactBottom(bool rbot);
		void setReactLeft(bool rleft);
		void setReactRight(bool rright);

		void setAllFalse();

		GameEntity();
		GameEntity(eGameEntity entityEnum);

		~GameEntity();
	};


}