#include "DrawManager.h"

bool DrawManager::instanceFlag = false;
DrawManager* DrawManager::single = nullptr;

DrawManager* DrawManager::getInstance()
{
	if (!instanceFlag)
	{
		single = new DrawManager();
		instanceFlag = true;
		return single;
	}
	else
	{
		return single;
	}
}