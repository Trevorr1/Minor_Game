#include "CollisionComponent.h"
#include "LevelManager.h"

using namespace overdose;
using namespace std;

CollisionComponent::CollisionComponent()
{
	
}



CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::receive(Component *subject, ComponentMessage message, GameEntity *object) {

}

void CollisionComponent::tick(GameEntity *entity) {
	int posx = (int)entity->getPosX();
	int posy = (int)entity->getPosY();
	int width = entity->getWidth();
	int height = entity->getHeight();
	eGameEntity entityEnum = entity->getEnum();

	vector<GameEntity> *gameEntities = LevelManager::getInstance()->getCurrentLevel()->getEntities();

	for (int i = 0; i < (int)gameEntities->size(); i++){
		GameEntity* other = &(gameEntities->at(i));
		if (entity != other)
		{
			int oposx = (int)other->getPosX();
			int oposy = (int)other->getPosY();
			int owidth = other->getWidth();
			int oheight = other->getHeight();

			if ((oposx > posx && oposx < posx + width || oposx + owidth > posx && oposx + owidth < posx + width) &&
				(oposy > posy && oposy < posy + height || oposy + oheight > posy && oposy + oheight < posy + height))
			{
				// do collision
				entity->broadcast(this, CollissionComponent_COLLISION, other);
				
			}


		}
	}
}