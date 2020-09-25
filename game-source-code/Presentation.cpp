#include "Presentation.h"

Presentation::Presentation(const int &width, const int &height) :
		screenWidth_(width), screenHeight_(height)
{
	window_.create(sf::VideoMode(screenWidth_, screenHeight_), "Super-Pacman");
}

bool Presentation::isWindowOpen() const
{
	return window_.isOpen();
}

void Presentation::handleEvents()
{
	auto event = sf::Event {};

	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window_.close();
			break;
		case sf::Event::KeyPressed:
			std::cout << "Pressed" << std::endl;
			break;
		case sf::Event::KeyReleased:
			std::cout << "Released" << std::endl;
			break;
		default:
			break;
		}
	}
}

void Presentation::render()
{
	window_.clear(sf::Color::Black);
	// Draw stuff you're gonna pass in later
	window_.display();
}
