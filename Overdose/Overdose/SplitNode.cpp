#include "SplitNode.h"

using namespace overdose;

SplitNode::SplitNode(TreeNode *parent)
	: TreeNode(parent)
{

}


SplitNode::~SplitNode()
{
}

void SplitNode::setLeft(TreeNode *node)
{
	this->left = node;
}

void SplitNode::setRight(TreeNode *node)
{
	this->right = node;
}

float SplitNode::lowerBound(int index)
{
	return 0;
}

float SplitNode::upperBound(int index)
{
	return 0;
}