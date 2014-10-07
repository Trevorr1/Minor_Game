#pragma once
namespace overdose {
	class TreeNode
	{
	protected:
		TreeNode *parent;

	public:
		TreeNode(TreeNode *parent);
		~TreeNode();

		virtual float lowerBound(int dimension);
		virtual float upperBound(int dimension);
	};
}


