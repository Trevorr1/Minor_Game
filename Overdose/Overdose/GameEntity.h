#pragma once
namespace overdose {
	class GameEntity
	{


	public:
		virtual void addComponent(Component &component);

		virtual void tick();

		GameEntity();

		~GameEntity();
	};


}