#include "Coordinates.h"

Coordinates::Coordinates(): x_(0), y_(0)
{

}

Coordinates::Coordinates(const float & x, const float & y): x_(x), y_(y)
{
}

void Coordinates::set(const float & x, const float & y)
{
	x_ = x;
	y_ = y;
}

void Coordinates::setX(const float & x)
{
		x_ = x;
}

void Coordinates::setY(const float & y)
{
		y_ = y;
}

float Coordinates::getX() const
{
	return x_;
}

float Coordinates::getY() const
{
	return y_;
}
