#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_
#include "Presentation.h"
#include "Coordinates.h"
#include "Maze.h"

class GameEngine
{
public:
	GameEngine(const Coordinates & gridSize, const Coordinates & screenDimentions);
	void runGame();
private:
	Presentation presentation_;
	Maze maze_;
};

#endif
