#include "BspTree.h"
#include "GameEntity.h"
#include "TreeNode.h"
#include "SplitNode.h"
#include "EndNode.h"

using namespace overdose;
using namespace std;

BspTree::BspTree(vector<GameEntity*> &list)
{
	this->list = &list;
}


BspTree::~BspTree()
{
}

TreeNode* BspTree::buildBSP(TreeNode* parent, int left, int right, int dimension) {
	// make a node that will be returned

	SplitNode* root = new SplitNode(parent);

	int size = right - left + 1;
	if (size <= 3) // manual sort if small
	{
		manualBSP(root, left, right, dimension);
	}
	else // quicksort if large
	{
		float median = (*list)[median3(left, right, dimension)]->getPosX();
		int partition = partitionIt(left, right, median, dimension);

		dimension++;
		dimension %= 2;

		root->setLeft(buildBSP(root, left, partition - 1, dimension));
		root->setRight(buildBSP(root, partition + 1, right, dimension));
	}
	return root;
}

void BspTree::manualBSP(SplitNode* root, int left, int right, int dimension)
{
	float l = 0, r = 0, rmin = 0;
	if (dimension == 0)
	{
		l = (*list)[left]->getPosX();
		r = (*list)[right]->getPosX();
		rmin = (*list)[right - 1]->getPosX();
	}
	else
	{
		l = (*list)[left]->getPosY();
		r = (*list)[right]->getPosY();
		rmin = (*list)[right - 1]->getPosY();
	}

	int size = right - left + 1;
	if (size <= 1) {

		EndNode* end = new EndNode(root, (*list)[left]);
		root->setLeft(end);

		return; // no sort necessary
	}
	if (size == 2) { // 2-sort left and right
		if (l > r) {
			swap(left, right);
		}
		EndNode *endLeft = new EndNode(root, (*this->list)[left]);
		EndNode *endRight = new EndNode(root, (*this->list)[right]);
		root->setLeft(endLeft);
		root->setRight(endRight);
		return;
	}
	else // size is 3
	{ // 3-sort left, center, & right
		if (l > rmin) {
			swap(left, right - 1); // left, center
		}
		if (l > r) {
			swap(left, right); // left, right
		}
		if (rmin > r) {
			swap(right - 1, right); // center, right
		}
		SplitNode *split = new SplitNode(root);
		// Set new split as left of root
		root->setLeft(split);
		root->setRight(new EndNode(root, (*this->list)[right]));

		// Set children of new SplitNode
		split->setLeft(new EndNode(split, (*this->list)[left]));
		split->setRight(new EndNode(split, (*this->list)[right - 1]));

		// Set bounds
		//root->setBounds(); // opdracht week 4
	}
}

int BspTree::partitionIt(int left, int right, float pivot, int dimension) {
	int leftPtr = left; // right of first elem
	int rightPtr = right - 1; // left of pivot

	bool run = true;
	float l = (*this->list)[leftPtr]->getPosition(dimension);
	float r = (*this->list)[rightPtr]->getPosition(dimension);
	while (run) {
		//       find bigger
		while (l <= pivot){
			leftPtr++;
			l = (*this->list)[leftPtr]->getPosition(dimension);
		}
		//       find smaller
		while (r >= pivot){
			rightPtr--;
			r = (*this->list)[rightPtr]->getPosition(dimension);
		}

		if (leftPtr >= rightPtr) // if pointers cross, partition done
		{
			run = false;
		}
		else // not crossed, so
		{
			swap(leftPtr, rightPtr); // swap elements
			l = (*this->list)[leftPtr]->getPosition(dimension);
			r = (*this->list)[rightPtr]->getPosition(dimension);
		}
	}
	swap(leftPtr, right - 1); // restore pivot
	return leftPtr; // return pivot location
}

int BspTree::median3(int left, int right, int dimension) {
	int center = (left + right) / 2;

	float l = (*this->list)[left]->getPosition(dimension);
	float r = (*this->list)[right]->getPosition(dimension);
	float c = (*this->list)[center]->getPosition(dimension);
	// order left & center
	if (l > c) {
		swap(left, center);
	}
	// order left & right
	if (l > r) {
		swap(left, right);
	}
	// order center & right
	if (c > r) {
		swap(center, right);
	}

	swap(center, right - 1); // put pivot on right
	return right - 1; // return median value
}

void BspTree::swap(int dex1, int dex2) {

	iter_swap(list->begin() + dex1, list->begin() + dex2);
	/*GameObject temp = this.list.get(dex1);
	this.list.set(dex1, this.list.get(dex2));
	this.list.set(dex2, temp);*/
}