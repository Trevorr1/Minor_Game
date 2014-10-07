#include "TreeNode.h"

using namespace overdose;

TreeNode::TreeNode(TreeNode *parent)
{
	this->parent = parent;
}


TreeNode::~TreeNode()
{
	this->parent = nullptr;
}

float TreeNode::lowerBound(int dimension)
{
	return 0;
}

float TreeNode::upperBound(int dimension)
{
	return 0;
}

