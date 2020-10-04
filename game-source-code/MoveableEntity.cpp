#include "MoveableEntity.h"
//
//MoveableEntity::MoveableEntity(Grid & grid, const float & offset):
//	moveOffset_(offset)
//{
//}
//
//MoveableEntity::~MoveableEntity()
//{
//}
//
//void MoveableEntity::adjustHitBox(const Direction & direction, HitBox & hitbox)
//{
//	if(!isMoveable(direction))
//		return;
//
//	switch(direction)
//	{
//	case Direction::UP:
//		setHitbox(hitbox.topLeft.getX(), hitbox.topLeft.getY() - moveOffset_);
//		break;
//	case Direction::DOWN:
//		setHitbox(hitbox.topLeft.getX(), hitbox.topLeft.getY() + moveOffset_);
//		break;
//	case Direction::LEFT:
//		setHitbox(hitbox.topLeft.getX() - moveOffset_, hitbox.topLeft.getY());
//		break;
//	case Direction::RIGHT:
//		setHitbox(hitbox.topLeft.getX() + moveOffset_, hitbox.topLeft.getY());
//	}
//}
//
//bool MoveableEntity::isMoveable(const Direction & direction) const
//{
//	bool moveable = false;
//	switch(direction)
//	{
//	case Direction::UP:
//		moveable = hitBox_.topRight.getY() - moveOffset_ >= 0;
//		break;
//	case Direction::DOWN:
//		moveable = hitBox_.bottomLeft.getY() + moveOffset_ <= screenY_;
//		break;
//	case Direction::LEFT:
//		moveable = hitBox_.topLeft.getX() - moveOffset_ >= 0;
//		break;
//	case Direction::RIGHT:
//		moveable = hitBox_.bottomRight.getX() + moveOffset_ <= screenX_;
//	}
//
//	return moveable;
//}
