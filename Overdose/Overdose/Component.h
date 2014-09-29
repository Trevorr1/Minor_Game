#pragma once
namespace overdose {
	class GameEntity;

	class Component
	{
	public:

		virtual void receive(Component &component, int message);

		virtual void tick(GameEntity &entity);
	};

}