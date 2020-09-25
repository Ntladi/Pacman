#ifndef ENTITY_H_
#define ENTITY_H_
#include "Coordinates.h"

struct HitBox
{
	Coordinates topLeft;
	Coordinates topRight;
	Coordinates bottomLeft;
	Coordinates bottomRight;
};

class InvalidDimentions{};

class Entity
{
public:
	Entity();
	virtual ~Entity();
	Entity(const Coordinates & position, const Coordinates & dimentions);
	bool isAlive() const;
	void kill();
	void resurrect();
	HitBox getVerticies() const;
protected:
	void setHitbox(const float & xPos, const float & yPos);
	float width_;
	float length_;
	bool status_;
	HitBox hitBox_;
};

#endif