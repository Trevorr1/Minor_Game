#pragma once
namespace overdose {
	class TreeNode
	{
	protected:
		TreeNode *parent;

	public:
		TreeNode(TreeNode *parent);
		~TreeNode();

		virtual float lowerBound(int index);
		virtual float upperBound(int index);
	};
}


