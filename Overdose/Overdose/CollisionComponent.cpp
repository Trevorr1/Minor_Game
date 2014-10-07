#include "CollisionComponent.h"

using namespace overdose;
using namespace std;

CollisionComponent::CollisionComponent()
{
	
}



CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::receive(Component &component, int message) {

}

void CollisionComponent::tick(GameEntity &entity) {
	int posx = entity.getPosX();
	int posy = entity.getPosY();
	int width = entity.getWidth();
	int height = entity.getHeight();

	vector<GameEntity> *gameEntities = LevelManager.getInstance().getCurrentLevel().getEntities();

	for (int i = 0; i < gameEntities->size(); i++){
		GameEntity* other = &(gameEntities->at(i));
		if (entity == *other)// overload operator?
		{
			int oposx = other->getPosX();
			int oposy = other->getPosY();
			int owidth = other->getWidth();
			int oheight = other->getHeight();

			if ((oposx > posx && oposx < posx + width || oposx + owidth > posx && oposx + owidth < posx + width) &&
				(oposy > posy && oposy < posy + height || oposy + oheight > posy && oposy + oheight < posy + height))
			{
				// do collision shit
				// entity.collided();??????
			}


		}
	}
}