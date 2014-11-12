#include "Camera.h"
#include "GameEntity.h"

using namespace overdose;

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Tick(Surface* aTarget)
{
	
}

void Camera::setEntityFocus(GameEntity* aFocusEntity)
{
	m_FocusEntity = aFocusEntity;
}

GameEntity* Camera::getFocusEnity()
{
	return m_FocusEntity;
}

unsigned int Camera::getPositionX()
{
	return m_CameraPositionX;
}

void Camera::setPositionX(unsigned int posx)
{
	m_CameraPositionX = posx;
}

unsigned int Camera::getPositionY()
{
	return m_CameraPositionY;
}

void Camera::setPositionY(unsigned int posy)
{
	m_CameraPositionY = posy;
}
