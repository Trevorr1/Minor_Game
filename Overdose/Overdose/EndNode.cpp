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
