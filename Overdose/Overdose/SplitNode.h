#pragma once
#include "TreeNode.h"
#include <algorithm>
namespace overdose {
	class SplitNode :
		public TreeNode
	{
	private:
		TreeNode *left, *right;
		float lowerbound[2];
		float upperbound[2];

	public:
		SplitNode(TreeNode *parent);
		~SplitNode();

		void setLeft(TreeNode *node);
		void setRight(TreeNode *node);

		virtual float lowerBound(int dimension);
		virtual float upperBound(int dimension);

		void setBounds();
	};

}