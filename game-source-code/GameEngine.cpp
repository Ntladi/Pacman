#include "GameEngine.h"

GameEngine::GameEngine(const Coordinates & gridSize, const Coordinates & screenDimentions, ifstream & mazeFile) :
		presentation_(screenDimentions), grid_(gridSize, screenDimentions,mazeFile), maze_(grid_), fruits_(grid_),
		pacman_(grid_)
{
}

void GameEngine::runGame()
{
	auto walls = maze_.getWalls();
	auto fruits = fruits_.getFruits();

	while(presentation_.isWindowOpen())
	{
		presentation_.getKeyInputs();
		for(auto wall : walls)
			presentation_.drawWall(wall);
		for(auto fruit : fruits)
			presentation_.drawFruit(fruit);
		// Logic stuff
		presentation_.render();
	}
}
