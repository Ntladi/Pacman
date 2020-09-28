#ifndef MOVEABLEENTITY_H_
#define MOVEABLEENTITY_H_
#include "Entity.h"
#include "Direction.h"

class MoveableEntity: Entity
{
public:
	MoveableEntity(const Coordinates & position, const Coordinates & dimentions, const Coordinates & screen, const float & offset);
	~MoveableEntity();
	bool isMoveable(const Direction & direction) const;
protected:
	float moveOffset_;
	float screenX_;
	float screenY_;
	void adjustHitBox(const Direction & direction);
};

#endif
