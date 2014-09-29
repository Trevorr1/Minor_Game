#pragma once
namespace overdose {
	class GameEntity
	{
	protected:
		float posX, posY, speedX, speedY;

	public:
		virtual void addComponent(Component &component);

		virtual void tick();

		float getPosX();
		float getPosY();
		float getSpeedX();
		float getSpeedY();

		void setSpeedX(float sx);
		void setSpeedY(float sy);
		void setPosX(float px);
		void setPosY(float py);

		GameEntity();

		~GameEntity();
	};


}