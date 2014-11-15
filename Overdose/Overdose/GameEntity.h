#pragma once
#include "stdafx.h"
#include "Enum.h"
#include "Component.h"
#include "ComponentMessage.h" 
#include "ScheduleForRemovalFlag.h"
#include <exception>
#include <stdarg.h>
#define FinalComponent nullptr


namespace overdose {
	class Component;
	class GameEntity : public ScheduleForRemovalFlag
	{
	private:
		std::vector<Component*> *componentListToAdd = new std::vector<Component*>;
	protected:
		float posX = 0.0, posY = 0.0, speedX = 0.0, speedY = 0.0;
		float startPosX = 0.0, startPosY = 0.0;
		float m_movementSpeed = 0.0f;
		float m_jumpSpeed = 0.0f;
		float width = 0, height = 0;
		eFacing m_Facing = FrontView;
		eGameEntity m_EntityEnum;
		
		bool m_scheduledForRemoval = false;
		bool m_jumping = false, m_falling = false;


		std::vector <int> *componentListToRemove = new std::vector < int >;
		std::vector<Component*> *componentList = new std::vector < Component* > ;
		std::vector<Component*> *componentListTemporary = new std::vector < Component* >;
		// only use 
		int* m_health = nullptr;
	public:
		virtual void delayedAddComponent(Component *component);

		virtual void addComponent(Component *component);

		virtual void tick(float dt);

		virtual std::vector<Component*>* getComponentList();

		void broadcast(Component *subject, ComponentMessage message, GameEntity *object);

		virtual void removeComponent(std::string componentString);

		virtual void addComponentTemporary(Component* component);


		bool isJumping();
		bool isFalling();
		void setJumping(bool isJumping);
		void setFalling(bool isFalling);

		float getJumpingSpeed();
		void setJumpingSpeed(float jspeed);

		bool unVulnerability;

		float getWidth();
		float getHeight();
		float getSpeedX();
		float getSpeedY();
		float getPosX();
		float getPosY();
		float getStartPosX(){ return startPosX; }
		float getStartPosY(){ return startPosY; }
		float getMovementSpeed();
		int getHealth();
		eFacing getFacing();

		float getPosition(int index); // voor bsp tree

		
		void setHealthPointer(int* health);
		eGameEntity getEnum();
		void setWidth(float width);
		void setHeight(float heigt);
		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);
		void setStartPosX(float x){ startPosX = x; }
		void setStartPosY(float y){ startPosY = y; }

		void setStartingPosition(float x, float y);
		void respawn();

		void setFacing(eFacing facing);
		void setMovementSpeed(float movementspeed);


		//void setCollided();

		GameEntity();
		GameEntity(eGameEntity entityEnum);
		GameEntity(eGameEntity entityEnum, Component *component, ...);

		~GameEntity();
	};


}