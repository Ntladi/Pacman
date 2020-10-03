#include "Presentation.h"

Presentation::Presentation(const Coordinates & screenDimentions) :
		direction_(Direction::LEFT), screenWidth_(screenDimentions.getX()), screenHeight_(screenDimentions.getY())
{
	window_.create(sf::VideoMode(screenWidth_, screenHeight_), "Super-Pacman");
	pacMan_.setFillColor(sf::Color::Yellow);
	pacMan_.setSize(sf::Vector2f(20,20));
	pacMan_.setPosition(440, 330);
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
		default:
			break;
		}
	}

	setDirection();

	return direction_;
}

void Presentation::drawWall(const Entity & wall)
{
	wall_.setFillColor(sf::Color::White);
	wall_.setPosition(wall.getPosition().getX(), wall.getPosition().getY());
	wall_.setSize(sf::Vector2f(wall.getDimentions().getX(), wall.getDimentions().getY()));
	window_.draw(wall_);
}

void Presentation::drawFruit(const Entity & fruit)
{
	fruit_.setFillColor(sf::Color::Magenta);
	fruit_.setPosition(fruit.getPosition().getX(), fruit.getPosition().getY());
	fruit_.setSize(sf::Vector2f(fruit.getDimentions().getX(), fruit.getDimentions().getY()));
	window_.draw(fruit_);
}

void Presentation::render()
{
	// Draw stuff you're gonna pass in later
	window_.draw(pacMan_);
	window_.display();
	window_.clear(sf::Color::Black);
}

Coordinates Presentation::getScreenDimentions() const
{
	return Coordinates {screenWidth_, screenHeight_};
}

void Presentation::setDirection()
{
	auto x = pacMan_.getPosition().x;
	auto y = pacMan_.getPosition().y;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction_ = Direction::UP;
		y = y - 1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction_ = Direction::DOWN;
		y = y + 1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction_ = Direction::LEFT;
		x = x - 1;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction_ = Direction::RIGHT;
		x = x + 1;
	}

	pacMan_.setPosition(x, y);
}
