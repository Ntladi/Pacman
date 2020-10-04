#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <fstream>
#include "Coordinates.h"
#include "Entity.h"
#include "Grid.h"
#include "Maze.h"
#include "Fruits.h"

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
	SUBCASE("A default entity's vertices are returned correctly")
	{
		auto entity = Entity {};
		CHECK(entity.getVerticies().topLeft.getX() == 0);
		CHECK(entity.getVerticies().topLeft.getY() == 0);
		CHECK(entity.getVerticies().topRight.getX() == 1);
		CHECK(entity.getVerticies().topRight.getY() == 0);
		CHECK(entity.getVerticies().bottomLeft.getX() == 0);
		CHECK(entity.getVerticies().bottomLeft.getY() == 1);
		CHECK(entity.getVerticies().bottomRight.getX() == 1);
		CHECK(entity.getVerticies().bottomRight.getY() == 1);
	}

	SUBCASE("A default entity's position is returned correctly")
	{
		auto entity = Entity {};
		CHECK(entity.getPosition().getX() == 0);
		CHECK(entity.getPosition().getY() == 0);
	}

	SUBCASE("An entity's vertices are initialized correctly")
	{
		auto x = 3.6f;
		auto y = 5.2f;
		auto width = 6.9f;
		auto length = 5.6f;
		auto entity = Entity {Coordinates{x, y}, Coordinates{width, length}};
		CHECK(entity.getVerticies().topLeft.getX() == x);
		CHECK(entity.getVerticies().topLeft.getY() == y);
		CHECK(entity.getVerticies().topRight.getX() == x + width);
		CHECK(entity.getVerticies().topRight.getY() == y);
		CHECK(entity.getVerticies().bottomLeft.getX() == x);
		CHECK(entity.getVerticies().bottomLeft.getY() == y + length);
		CHECK(entity.getVerticies().bottomRight.getX() == x + width);
		CHECK(entity.getVerticies().bottomRight.getY() == y + length);
	}

	SUBCASE("An entity's position is initialized correctly")
	{
		auto x = 3.6f;
		auto y = 5.2f;
		auto width = 6.9f;
		auto length = 5.6f;
		auto entity = Entity {Coordinates{x, y}, Coordinates{width, length}};
		CHECK(entity.getPosition().getX() == x);
		CHECK(entity.getPosition().getY() == y);

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

TEST_CASE("Grid Tests")
{
	auto gridSize = Coordinates(23,25);
	auto screenDimentions = Coordinates(920,750);

	SUBCASE("A maze is properly loaded from a file")
	{
		auto file = std::ifstream("Maze.txt");
		CHECK(file.is_open());
		file.close();
	}

	auto file = std::ifstream("Maze.txt");
	auto grid = Grid(gridSize, screenDimentions, file);

	SUBCASE("The grid dimentions are prperly set")
	{
		auto matrix = grid.getMatrix();
		CHECK(matrix.size() == 25); // Rows
		CHECK(matrix.at(0).size() == 23); //Columns
	}

	SUBCASE("The screen dimensions of a grid block are returned properly")
	{
		auto dimensions = grid.getBlockDimentions();
		CHECK(dimensions.getX() == 40);
		CHECK(dimensions.getY() == 30);
	}

	SUBCASE("A block's screen coordinates can be converted to a grid position")
	{
		auto position = grid.convertToGridPos(0, 0);
		CHECK(position.getX() == 0);
		CHECK(position.getY() == 0);

		position = grid.convertToGridPos(40, 30);
		CHECK(position.getX() == 1);
		CHECK(position.getY() == 1);

		position = grid.convertToGridPos(79, 59);
		CHECK(position.getX() == 1);
		CHECK(position.getY() == 1);

		position = grid.convertToGridPos(79.999, 59.999);
		CHECK(position.getX() == 1);
		CHECK(position.getY() == 1);

		position = grid.convertToGridPos(80, 60);
		CHECK(position.getX() == 2);
		CHECK(position.getY() == 2);

		position = grid.convertToGridPos(120, 60);
		CHECK(position.getX() == 3);
		CHECK(position.getY() == 2);

		position = grid.convertToGridPos(910, 740);
		CHECK(position.getX() == 22);
		CHECK(position.getY() == 24);
	}

	SUBCASE("A block's grid position can be converted to screen coordinates")
	{
		auto position = grid.convertToScreenPos(0, 0);
		CHECK(position.getX() == 0);
		CHECK(position.getY() == 0);

		position = grid.convertToScreenPos(1, 1);
		CHECK(position.getX() == 40);
		CHECK(position.getY() == 30);

		position = grid.convertToScreenPos(2, 1);
		CHECK(position.getX() == 40);
		CHECK(position.getY() == 60);

		position = grid.convertToScreenPos(1, 2);
		CHECK(position.getX() == 80);
		CHECK(position.getY() == 30);

		position = grid.convertToScreenPos(24, 22);
		CHECK(position.getX() == 880);
		CHECK(position.getY() == 720);
	}

	file.close();
}

TEST_CASE("Static Object Tests")
{
	auto file = std::ifstream("Maze.txt");
	auto grid = Grid(Coordinates(23,25), Coordinates(920,750), file);

	SUBCASE("The correct number of maze wall objects is returned")
	{
		auto maze = Maze(grid);
		auto counter = 0;
		for(auto mat: grid.getMatrix())
			for(auto index: mat)
			{
				if(index == 1 || index == 2)
					counter ++;
				if(index == 3 || index == 4 ||
				   index == 5 || index == 6)
					counter +=2;
			}

		CHECK(maze.getWalls().size() == counter);
	}

	SUBCASE("The correct number of fruit objects is returned")
	{
		auto fruits = Fruits(grid);
		auto counter = 0;

		for(auto mat: grid.getMatrix())
			for(auto index: mat)
				if(index == 7)
					counter++;

		CHECK(fruits.getFruits().size() == counter);
	}
}

TEST_CASE("Pacman Tests")
{

}
