#pragma once
#include "stdafx.h"
#include "Enum.h"
#include "Component.h"
#include "ComponentMessage.h" 
#include "ScheduleForRemovalFlag.h"
#include <exception>
#include <stdarg.h>
#include "Toolbox.h"
#define FinalComponent nullptr


namespace overdose {
	class Component;
	class GameEntity : public ScheduleForRemovalFlag
	{
	private:
		std::vector<Component*> *componentListToAdd = new std::vector<Component*>;
	protected:
		float posX = 0.0f, posY = 0.0f, speedX = 0.0f, speedY = 0.0f;
		float startPosX = 0.0f, startPosY = 0.0f;
		float m_accelerationX = 0.0f;
		float m_movementSpeed = 0.0f;
		float m_maxSpeed = 0.0f;
		float m_jumpSpeed = 0.0f;
		float width = 0, height = 0;
		eFacing m_Facing = FrontView;
		eGameEntity m_EntityEnum;
		
		bool m_scheduledForRemoval = false;
		bool m_jumping = false, m_falling = true;


		std::vector <int> *componentListToRemove = new std::vector < int >;
		std::vector<Component*> *componentList = new std::vector < Component* > ;
		std::vector<Component*> *componentListTemporary = new std::vector < Component* >;
		// only use 
		int* m_health = nullptr;
	public:
		virtual void delayedAddComponent(Component *component);

		void addComponent(Component *component);

		virtual void tick(float dt);

		virtual std::vector<Component*>* getComponentList();

		void broadcast(Component *subject, ComponentMessage message, GameEntity *object);

		void broadcastBatchMessages(Component *subject, std::map<ComponentMessage, GameEntity*> messages);

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

		virtual void setStartingPosition(float x, float y);
		void respawn();

		void setFacing(eFacing facing);
		void setMovementSpeed(float movementspeed);


		GameEntity();
		GameEntity(eGameEntity entityEnum);
		GameEntity(eGameEntity entityEnum, Component *component, ...);

		virtual ~GameEntity();

		// for acceleration of the sideway movement
		void resetAcclX(){ m_accelerationX = 0.0f; }
		void setAcclX(float accl) { m_accelerationX = accl; }
		float getAcclX() { return m_accelerationX; }
		void resetGravity() { speedY = 1.0f; }

	};


}