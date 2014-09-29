#pragma once
namespace overdose {
	class ComponentContainer
	{


	public:
		virtual void addComponent(Component component);

		virtual void tick();

		ComponentContainer();

		~ComponentContainer();
	};


}