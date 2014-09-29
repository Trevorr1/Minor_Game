#pragma once

namespace overdose {
	class Component
	{
	public:

		virtual void receive(Component &component, int message);

		virtual void tick(GameEntity &entity);
	};

}