#pragma once
#include "TreeNode.h"
#include "stdafx.h"
#include "GameEntity.h"


namespace overdose {
	class EndNode :
		public TreeNode
	{
	private:
		GameEntity *gameEntity;

	public:
		EndNode(TreeNode *parent, GameEntity *gameEntity);
		~EndNode();
	};
}
