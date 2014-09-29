#pragma once
namespace overdose {
	class DummyComponent : public Component
	{
		void receive(Component &component, int message);
		void tick(GameEntity &entity);
	};
}