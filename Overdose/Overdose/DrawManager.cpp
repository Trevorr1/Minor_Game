#include "DrawManager.h"

DrawManager &DrawManager::getInstance()
{
	static DrawManager _instance;
	return _instance;
}

void DrawManager::createLevelSurface(int width, int height)
{
	delete m_Level;
	m_Level = new Surface(width, height);
}

void DrawManager::convertLevelToCamera(int xoffset, int yoffset)
{
	m_Level->CopyTo(m_Camera, -xoffset, yoffset);
}