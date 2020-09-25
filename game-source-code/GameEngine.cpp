#include "GameEngine.h"

GameEngine::GameEngine(const int &width, const int &height) :
		presentation_(width, height)
{

}

void GameEngine::runGame()
{
	while(presentation_.isWindowOpen())
	{
		presentation_.handleEvents();
		// Logic stuff
		presentation_.render();
	}
}
