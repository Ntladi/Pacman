#ifndef PRESENTATION_H_
#define PRESENTATION_H_
#include "SFML/Graphics.hpp"
#include <iostream>

class Presentation
{
public:
	Presentation(const int & width, const int & height);
	bool isWindowOpen() const;
	void handleEvents();
	void render();
private:
	void setEvent();
	const int screenWidth_;
	const int screenHeight_;
	sf::RenderWindow window_;
};

#endif
