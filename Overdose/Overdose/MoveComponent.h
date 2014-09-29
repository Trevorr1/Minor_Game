#pragma once
namespace overdose{
	class MoveComponent :
		public Component
	{
	public:
		void receive(Component &component, int message);
		void tick(GameEntity &entity);
	};

}