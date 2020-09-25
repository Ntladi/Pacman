#include "Presentation.h"

Presentation::Presentation(const int &width, const int &height) :
		direction_(Direction::LEFT), screenWidth_(width), screenHeight_(height)
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
			setEvent(event.key.code);
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

void Presentation::setEvent(const int & code)
{
	switch (code)
	{
	case sf::Keyboard::Up:
		direction_ = Direction::UP;
		break;
	case sf::Keyboard::Down:
		direction_ = Direction::DOWN;
		break;
	case sf::Keyboard::Left:
		direction_ = Direction::LEFT;
		break;
	case sf::Keyboard::Right:
		direction_ = Direction::RIGHT;
		break;
	default:
		break;
	}
}
