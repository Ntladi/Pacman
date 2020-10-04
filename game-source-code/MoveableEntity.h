#ifndef MOVEABLEENTITY_H_
#define MOVEABLEENTITY_H_
#include "Entity.h"
#include "Direction.h"
#include "Grid.h"

class MoveableEntity: protected Entity
{
public:
	MoveableEntity(const Coordinates & position, const Coordinates & dimentions, const Coordinates & screen, const float & offset);
	~MoveableEntity();
	bool isMoveable(const Direction & direction) const;
protected:
	const float moveOffset_;
	void adjustHitBox(const Direction & direction);
};

#endif
