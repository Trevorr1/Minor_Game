#include "EndNode.h"
#include "stdafx.h"

using namespace overdose;

EndNode::EndNode(TreeNode *parent, GameEntity *gameEntity) 
	: TreeNode(parent)
{
	this->gameEntity = gameEntity;
}


EndNode::~EndNode()
{
}

float EndNode::lowerBound(int dimension)
{
	if (dimension == 0)
		return this->gameEntity->getPosX();
	if (dimension == 1)
		return this->gameEntity->getPosY();
	return 0;
}

float EndNode::upperBound(int dimension)
{
	if (dimension == 0)
		return this->gameEntity->getPosX();
	if (dimension == 1)
		return this->gameEntity->getPosY();
	return 0;
}

GameEntity* EndNode::getGameEntity()
{
	return this->gameEntity;
}