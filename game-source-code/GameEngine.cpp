#include "GameEngine.h"

GameEngine::GameEngine(const Coordinates & gridSize, const Coordinates & screenDimentions, ifstream & mazeFile) :
		presentation_(screenDimentions), grid_(gridSize, screenDimentions,mazeFile), maze_(grid_)
{
}

void GameEngine::runGame()
{
	while(presentation_.isWindowOpen())
	{
		presentation_.getKeyInputs();
		auto walls = maze_.getWalls();
		for(auto wall : walls)
			presentation_.drawWalls(wall);
		// Logic stuff
		presentation_.render();
	}
}
