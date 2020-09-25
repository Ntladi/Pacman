#include "Coordinates.h"

Coordinates::Coordinates(): x_(0), y_(0)
{

}

Coordinates::Coordinates(const float & x, const float & y): x_(x), y_(y)
{
	if(x_ < 0 || y_ < 0)
		throw InvalidCoordinates {};
}

void Coordinates::set(const float & x, const float & y)
{
	if(x < 0 || y < 0)
		return;

	x_ = x;
	y_ = y;
}

void Coordinates::setX(const float & x)
{
	if(x >= 0)
		x_ = x;
}

void Coordinates::setY(const float & y)
{
	if(y >= 0)
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
