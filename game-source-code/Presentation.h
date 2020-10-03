#ifndef PRESENTATION_H_
#define PRESENTATION_H_
#include "SFML/Graphics.hpp"
#include "Direction.h"
#include "Coordinates.h"
#include "Entity.h"
#include <iostream>

class Presentation
{
public:
	Presentation(const Coordinates & screenDimentions);
	bool isWindowOpen() const;
	Direction getKeyInputs();
	Coordinates getScreenDimentions() const;
	void drawWall(const Entity & wall);
	void drawFruit(const Entity & wall);
	void render();
private:
	void setDirection();
private:
	Direction direction_;
	const float screenWidth_;
	const float screenHeight_;
	sf::RenderWindow window_;
	sf::RectangleShape wall_;
	sf::RectangleShape fruit_;
	sf::RectangleShape pacMan_;
};

#endif
