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

