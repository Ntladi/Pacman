#include "GameEngine.h"

GameEngine::GameEngine(const Coordinates & gridSize, const Coordinates & screenDimentions) :
		presentation_(screenDimentions), maze_(gridSize, screenDimentions)
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
