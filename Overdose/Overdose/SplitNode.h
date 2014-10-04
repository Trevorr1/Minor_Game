#pragma once
#include "TreeNode.h"
namespace overdose {
	class SplitNode :
		public TreeNode
	{
	private:
		TreeNode *left, *right;
	public:
		SplitNode(TreeNode *parent);
		~SplitNode();

		void setLeft(TreeNode *node);
		void setRight(TreeNode *node);

		virtual float lowerBound(int index);
		virtual float upperBound(int index);
	};

}