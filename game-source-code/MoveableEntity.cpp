#include "MoveableEntity.h"

MoveableEntity::MoveableEntity(const Coordinates & position, const Coordinates & dimentions, const Coordinates & screen, const float & offset):
	Entity(position, dimentions), moveOffset_(offset), screenX_(screen.getX()), screenY_(screen.getY())
{
}

MoveableEntity::~MoveableEntity()
{
}

void MoveableEntity::adjustHitBox(const Direction & direction)
{
	if(!isMoveable(direction))
		return;

	switch(direction)
	{
	case Direction::UP:
		setHitbox(hitBox_.topLeft.getX(), hitBox_.topLeft.getY() - moveOffset_);
		break;
	case Direction::DOWN:
		setHitbox(hitBox_.topLeft.getX(), hitBox_.topLeft.getY() + moveOffset_);
		break;
	case Direction::LEFT:
		setHitbox(hitBox_.topLeft.getX() - moveOffset_, hitBox_.topLeft.getY());
		break;
	case Direction::RIGHT:
		setHitbox(hitBox_.topLeft.getX() + moveOffset_, hitBox_.topLeft.getY());
	}
}

bool MoveableEntity::isMoveable(const Direction & direction) const
{
	bool moveable = false;
	switch(direction)
	{
	case Direction::UP:
		moveable = hitBox_.topRight.getY() - moveOffset_ >= 0;
		break;
	case Direction::DOWN:
		moveable = hitBox_.bottomLeft.getY() + moveOffset_ <= screenY_;
		break;
	case Direction::LEFT:
		moveable = hitBox_.topLeft.getX() - moveOffset_ >= 0;
		break;
	case Direction::RIGHT:
		moveable = hitBox_.bottomRight.getX() + moveOffset_ <= screenX_;
	}

	return moveable;
}
