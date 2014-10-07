#include "SplitNode.h"

using namespace overdose;

SplitNode::SplitNode(TreeNode *parent)
	: TreeNode(parent)
{
	for (int i = 0; i < 2; i++)
	{

		lowerbound[i] = (float)i;
		upperbound[i] = (float)i;
	}
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

float SplitNode::lowerBound(int dimension)
{
	float l = 0, r = 0;
	if (left != nullptr)
		l = left->lowerBound(dimension);
	if (right != nullptr)
		r = right->lowerBound(dimension);

	return std::min(l, r);
}

float SplitNode::upperBound(int dimension)
{
	float l = 0, r = 0;
	if (left != nullptr)
		l = left->upperBound(dimension);
	if (right != nullptr)
		r = right->upperBound(dimension);

	return std::max(l, r);
}

void SplitNode::setBounds()
{
	int index = 0;

	// set the x values
	lowerbound[index] = lowerBound(index);
	upperbound[index] = upperBound(index);

	index++;
	index %= 2;

	// set the y values
	lowerbound[index] = lowerBound(index);
	upperbound[index] = upperBound(index);
}