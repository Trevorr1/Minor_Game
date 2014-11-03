#pragma once
#include "Component.h"
namespace overdose{
	class KnockBackComponent : public Component
	{
	public:
		KnockBackComponent();
		virtual ~KnockBackComponent();

		void receive(Component *subject, ComponentMessage message, GameEntity *object);
		void tick(float dt, GameEntity *entity);

		std::string getComponentID();
	private:
		bool knockBackToLeft = false;
		bool knockBackToRight = false;
		bool knockBackToTop = false;
		const int knockbackValue = 15;
	};
}
