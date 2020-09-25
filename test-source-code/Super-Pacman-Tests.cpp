#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Coordinates.h"
#include "Entity.h"

TEST_CASE("Coordinate Tests")
{
	SUBCASE("A default coordinate object is initialized correctly")
	{
		auto coordinates = Coordinates{};
		CHECK(coordinates.getX() == 0);
		CHECK(coordinates.getY() == 0);
	}

	SUBCASE("A coordinate object is initialized correctly")
	{
		auto coordinates = Coordinates{3.1f, 6.8f};
		CHECK(coordinates.getX() == 3.1f);
		CHECK(coordinates.getY() == 6.8f);
	}

	SUBCASE("A coordinate object cannot be initialized with negative values")
	{
		CHECK_THROWS_AS(Coordinates(-3.1f, 6.8f), InvalidCoordinates);
		CHECK_THROWS_AS(Coordinates(3.1f, -6.8f), InvalidCoordinates);
		CHECK_THROWS_AS(Coordinates(-3.1f, -6.8f), InvalidCoordinates);
	}

	SUBCASE("The x-coordinate can be changed")
	{
		auto coordinates = Coordinates{2.5f, 9.3f};
		coordinates.setX(4.5f);
		CHECK(coordinates.getX() == 4.5f);
		CHECK(coordinates.getY() == 9.3f);
	}

	SUBCASE("The y-coordinate can be changed")
	{
		auto coordinates = Coordinates{8.9f, 16.8f};
		coordinates.setY(32.5f);
		CHECK(coordinates.getX() == 8.9f);
		CHECK(coordinates.getY() == 32.5f);
	}

	SUBCASE("The x-coordinate cannot be changed to a negative value")
	{
		auto coordinates = Coordinates{18.5f, 11.7f};
		coordinates.setX(-16.7f);
		CHECK(coordinates.getX() == 18.5f);
		CHECK(coordinates.getY() == 11.7f);
	}

	SUBCASE("The y-coordinate cannot be changed to a negative value")
	{
		auto coordinates = Coordinates{52.8f, 39.6f};
		coordinates.setY(-88.5f);
		CHECK(coordinates.getX() == 52.8f);
		CHECK(coordinates.getY() == 39.6f);
	}
}

TEST_CASE("Entity Tests")
{
	SUBCASE("A default entity object is initialised correctly")
	{
		auto entity = Entity {};
		CHECK(entity.isAlive() == true);
		CHECK(entity.getVerticies().topLeft.getX() == 0);
		CHECK(entity.getVerticies().topLeft.getY() == 0);
		CHECK(entity.getVerticies().topRight.getX() == 1);
		CHECK(entity.getVerticies().topRight.getY() == 0);
		CHECK(entity.getVerticies().bottomLeft.getX() == 0);
		CHECK(entity.getVerticies().bottomLeft.getY() == 1);
		CHECK(entity.getVerticies().bottomRight.getX() == 1);
		CHECK(entity.getVerticies().bottomRight.getY() == 1);
	}

	SUBCASE("An entity object is initialized correctly")
	{
		auto x = 3.6f;
		auto y = 5.2f;
		auto width = 6.9f;
		auto length = 5.6f;
		auto entity = Entity {Coordinates{x, y}, Coordinates{width, length}};
		CHECK(entity.isAlive() == true);
		CHECK(entity.getVerticies().topLeft.getX() == x);
		CHECK(entity.getVerticies().topLeft.getY() == y);
		CHECK(entity.getVerticies().topRight.getX() == x + width);
		CHECK(entity.getVerticies().topRight.getY() == y);
		CHECK(entity.getVerticies().bottomLeft.getX() == x);
		CHECK(entity.getVerticies().bottomLeft.getY() == y + length);
		CHECK(entity.getVerticies().bottomRight.getX() == x + width);
		CHECK(entity.getVerticies().bottomRight.getY() == y + length);
	}

	SUBCASE("An entity can be killed")
	{
		auto entity = Entity {};
		CHECK(entity.isAlive() == true);
		entity.kill();
		CHECK(entity.isAlive() == false);
	}

	SUBCASE("An entity can be resurrected")
	{
		auto entity = Entity {};
		CHECK(entity.isAlive() == true);
		entity.kill();
		CHECK(entity.isAlive() == false);
		entity.resurrect();
		CHECK(entity.isAlive() == true);
	}
}
