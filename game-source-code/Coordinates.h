#ifndef COORDINATES_H_
#define COORDINATES_H_

class InvalidCoordinates{};

class Coordinates
{
public:
	Coordinates();
	Coordinates(const float & x, const float & y);
	void setX(const float & x);
	void setY(const float & y);
	void set(const float & x, const float & y);
	float getX() const;
	float getY() const;
private:
	float x_;
	float y_;
};

#endif
