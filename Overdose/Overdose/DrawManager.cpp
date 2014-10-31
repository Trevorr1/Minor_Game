#include "DrawManager.h"

DrawManager &DrawManager::getInstance()
{
	static DrawManager _instance;
	return _instance;
}