#include "HUDEntity.h"

using namespace overdose;

HUDEntity::HUDEntity(int x, int y)
{
	posX = x;
	posY = y;
}


HUDEntity::~HUDEntity()
{
	//m_DrawComponent = nullptr; // in GameEntity
}
