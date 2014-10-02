#pragma once

#include "stdafx.h"
#include <vector>
#include <algorithm>

namespace overdose {

	class BspTree
	{
	private:
		vector<GameEntity*> *list;

		void manualBSP(SplitNode* root, int left, int right, int dimension);
		void swap(int dex1, int dex2);

		int partitionIt(int left, int right, float pivot, int dimension);
		int median3(int left, int right, int dimension);
		float getMedian(int left, int right, int dimension);

	public:
		BspTree(vector<GameEntity*> &list);
		~BspTree();

		TreeNode* buildBSP(TreeNode* root, int left, int right, int dimension);

	};
}
