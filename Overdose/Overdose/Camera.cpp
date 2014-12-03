#include "Camera.h"
#include "GameEntity.h"
#include "DrawManager.h"

using namespace overdose;

Camera::Camera(int levelWidth)
{
	m_WorldCameraPositionX = 0;
	m_WorldCameraPositionY = 0;

	m_FocusEntity = nullptr;
	m_LevelWidth = levelWidth;
}


Camera::~Camera()
{
}

void Camera::Tick(float dt)
{
	if (m_FocusEntity != nullptr)
	{
		float playerx = m_FocusEntity->getPosX();
		float playery = m_FocusEntity->getPosY();

		float playerCameraX = playerx - m_WorldCameraPositionX;

		float playerspeedx = m_FocusEntity->getSpeedX() * dt;

		int screenWidth = 940; //get this from game.h or somehting :D
		int playerWidth = 27;

		float screenOffset = 400;

		if ((playerCameraX > screenWidth - screenOffset) && (m_WorldCameraPositionX + screenWidth < m_LevelWidth - playerWidth))
		{
			m_WorldCameraPositionX = playerx + screenOffset - screenWidth;
		}

		if (playerCameraX < screenOffset && m_WorldCameraPositionX > 0)
		{
			float result = playerx - screenOffset;
			if (result < 0){
				m_WorldCameraPositionX = 0;
			}
			else{
				m_WorldCameraPositionX = playerx - screenOffset;
			}
		}
	}
	
	DrawManager::getInstance().convertLevelToCamera(m_WorldCameraPositionX, m_WorldCameraPositionY);

	//int tile = 0;
	//int scroll_x, scroll_y;
	//int offset_x, offset_y;

	//for (int y = 0; y < 10; y++) // hardcoded remove me later
	//{
	//	scroll_y = y + (m_WorldCameraPositionY / 32); // hardcoded remove me later

	//	for (int x = 0; x < 12; x++) //hardcoded remove me later
	//	{
	//		scroll_x = x + (m_WorldCameraPositionX / 32); // hardcoded remove me later

	//		offset_x = m_WorldCameraPositionX & (32 - 1); // hardcoded remove me later
	//		offset_y = m_WorldCameraPositionY & (32 - 1); // hardcoded remove me later

	//		tile = m_TileMap[scroll_x*32+scroll_y];
	//		m_TileAssets[tile].setPosX((x * 32) - offset_x);
	//		m_TileAssets[tile].setPosY((y * 32) - offset_y);
	//		//m_TileAssets[tile].getComponentList()->at(0)->
	//		//m_TileAssets[tile].CopyTo(surface, (x * 32) - offset_x, (y * 32) - offset_y); // hardcoded remove me later
	//	}
	//}
}

void Camera::setTileMap(int tileMap[], int size)
{
	for (int i = 0; i < size; i++)
	{
		m_TileMap[i] = tileMap[i];
	}
}

void Camera::setTileAssets(Tile* tileAssets)
{
	for (int i = 0; i < 3; i++)
	{
		m_TileAssets[i] = *tileAssets;
	}
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
	return m_WorldCameraPositionX;
}

void Camera::setPositionX(unsigned int posx)
{
	m_WorldCameraPositionX = posx;
}

unsigned int Camera::getPositionY()
{
	return m_WorldCameraPositionY;
}

void Camera::setPositionY(unsigned int posy)
{
	m_WorldCameraPositionY = posy;
}
