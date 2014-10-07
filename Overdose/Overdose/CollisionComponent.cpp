#include "CollisionComponent.h"

using namespace overdose;

CollisionComponent::CollisionComponent(int x, int y, int w, int h)
{
	collisionRect.x = x;
	collisionRect.y = y;
	collisionRect.w = w;
	collisionRect.h = h;
}

void CollisionComponent::setRectangle(int x, int y,int w,int h)
{
}


CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::receive(Component &component, int message) {

}

void CollisionComponent::tick(GameEntity &entity) {}