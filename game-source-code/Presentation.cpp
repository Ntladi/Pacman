#include "Presentation.h"

Presentation::Presentation(const Coordinates & screenDimentions) :
		direction_(Direction::LEFT), screenWidth_(screenDimentions.getX()), screenHeight_(screenDimentions.getY())
{
	window_.create(sf::VideoMode(screenWidth_, screenHeight_), "Super-Pacman");
}

bool Presentation::isWindowOpen() const
{
	return window_.isOpen();
}

Direction Presentation::getKeyInputs()
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

	return direction_;
}

void Presentation::drawWalls(const Entity & wall)
{
	wall_.setFillColor(sf::Color::White);
	wall_.setPosition(wall.getPosition().getX(), wall.getPosition().getY());
	wall_.setSize(sf::Vector2f(wall.getDimentions().getX(), wall.getDimentions().getY()));
	window_.draw(wall_);
}

void Presentation::render()
{
	// Draw stuff you're gonna pass in later
	window_.display();
	window_.clear(sf::Color::Black);
}

Coordinates Presentation::getScreenDimentions() const
{
	return Coordinates {screenWidth_, screenHeight_};
}

void Presentation::setEvent(const int &code)
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
